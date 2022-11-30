%{
 
#include <stdio.h>
#include <stdlib.h>
 
extern int yylex();
extern int yyparse();
extern FILE* yyin;
 
void yyerror(const char* s);


struct symbol {
    char* name;
    int type;
    union {
        int ival;
    } value;
    struct symbol* next;
};

const int TYPE_IVAL = 0;
struct symbol* symboltable = NULL;

struct symbol* putsymbol(char* name, int type) {
    struct symbol* sym = (struct symbol *) malloc(sizeof(struct symbol));
    sym->type = type;
    sym->name = malloc(strlen(name)+1);
    strncpy(sym->name, name, strlen(name)+1);

    if(type == TYPE_IVAL) {
        sym->value.ival = 0;
    }
    
    sym->next = symboltable;
    symboltable = sym;
    
    return sym;
}

struct symbol* getsymbol(char* name) {
    struct symbol* p = symboltable;
    struct symbol* result = NULL;
    
    while(p != NULL) {
        if(strcmp(p->name, name) == 0) {
            // only catch the first instance, since newer items are placed in the front of the list
            if(result == NULL) {
                result = p;
            }
            
            break;
        }
        
        p = p->next;
    }
    
    return result;
}

%}
 
%union {
    int ival;
    float fval;
	char* sval;
}
 
%token<ival> T_INT
%token<fval> T_FLOAT
%token<sval> T_ID
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_LEFT T_RIGHT T_NEWLINE
 

%type<ival> expression
%type<fval> mixed_expression
%type<sval> id_expression
%start calc
 
%%
 
calc:                                                       { printf("EOF\n"); exit(0); }
    | mixed_expression T_NEWLINE                            { printf("Result = %f\n", $1); exit(0);}
    | 
	| expression T_NEWLINE                                  { printf("Result = %d\n", $1); exit(0); } // no return value needed, no type
 
mixed_expression: T_FLOAT                 		            { $$ = $1; }
	  | mixed_expression T_PLUS mixed_expression	        { $$ = $1 + $3; }
	  | mixed_expression T_MINUS mixed_expression	        { $$ = $1 - $3; }
	  | mixed_expression T_MULTIPLY mixed_expression        { $$ = $1 * $3; }
	  | mixed_expression T_DIVIDE mixed_expression	        { $$ = $1 / $3; }
	  | T_LEFT mixed_expression T_RIGHT		                { $$ = $2; }
	  | expression T_PLUS mixed_expression	 	            { $$ = $1 + $3; }
	  | expression T_MINUS mixed_expression	 	            { $$ = $1 - $3; }
	  | expression T_MULTIPLY mixed_expression 	            { $$ = $1 * $3; }
	  | expression T_DIVIDE mixed_expression	            { $$ = $1 / $3; }
	  | mixed_expression T_PLUS expression	 	            { $$ = $1 + $3; }
	  | mixed_expression T_MINUS expression	 	            { $$ = $1 - $3; }
	  | mixed_expression T_MULTIPLY expression 	            { $$ = $1 * $3; }
	  | mixed_expression T_DIVIDE expression	            { $$ = $1 / $3; }
	  | expression T_DIVIDE expression		                { $$ = $1 / (float)$3; }

expression: T_INT				                            { $$ = $1; }
	  | expression T_PLUS expression	                    { $$ = $1 + $3; }
	  | expression T_MINUS expression	                    { $$ = $1 - $3; }
	  | expression T_MULTIPLY expression	                { $$ = $1 * $3; }
	  | T_LEFT expression T_RIGHT		                    { $$ = $2; }

id_expression: T_ID				                            { $$ = $1; }

%%
 
int main() {
    yyin = stdin;
     
    do {
        yyparse();
    } while(!feof(yyin));
}
 
void yyerror(const char* s) {
    fprintf(stderr, "Parse error: %s\n", s);
    exit(1);
}
 
// https://github.com/meyerd/flex-bison-example
// the token types are as defined in the %union above