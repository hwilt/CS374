%option noyywrap       
 
%{
#include <stdio.h>
 
#define YY_DECL int yylex()
 
#include "calc.tab.h"
 
%}
 
%%
 
[ \t]                   ; // ignore all whitespace
[0-9]+                  {yylval.ival = atoi(yytext); return T_INT;}
[0-9]*\.[0-9]+          {yylval.fval = atof(yytext); return T_FLOAT;}
[a-z]*                  {yylval.sval = yytext; return T_ID;}
"+"                     {return T_PLUS;}
"-"                     {return T_MINUS;}
"*"                     {return T_MULTIPLY;}
"/"                     {return T_DIVIDE;}
"("                     {return T_LEFT;}
")"                     {return T_RIGHT;}
":="                    {return T_ASSIGN;}
\n                      {return T_NEWLINE;}
 
%%
 
// https://github.com/meyerd/flex-bison-example
// noyywrap assumes that there are no additional files to be parsed
// Floating point numbers are not supported