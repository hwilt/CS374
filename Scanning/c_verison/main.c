/*
Grammer;

num: [0-9]+
please: ["please"] 
op: + | - 


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ~~~~~~~~~~~~ TOKEN Structure/Methods ~~~~~~~~~~~~~~
struct Token{
    char* type;
    char* string;
};

struct Token allTokens[]; 					//array of tokens
int sizeTokens = 0; 						//size of array of tokens

void addToken(char* type, char* string){
	struct Token newToken;
	newToken.type = type;
	newToken.string = string;
	allTokens[sizeTokens] = newToken;
	sizeTokens++;							// increment size of array of tokens
}

void getToken(int index){
	printf("Token %d;\t Type: %s, String: %s\n",index, allTokens[index].type, allTokens[index].string);
}


void printTokenArray(){
	for(int i = 0; i < sizeTokens; i++){
		getToken(i);	
	}
}

//~~~~~~~~~~ SCANNER Methods ~~~~~~~~~~~~

char character;

char pop(){
    char ch = getchar();
    //printf("Popped %c\n", ch);
    return ch;
}

char peek(){
    char ch = pop();
    ungetc(ch, stdin);
    //printf("Pushed %c\n", ch);
    return ch;
}

void readint(){
	int numchars = 0;
	char* val = (char*) malloc(sizeof(char));

	character = peek();
	while(isdigit(character)){
		pop();

		numchars++;
		val = (char*) realloc(val, (numchars+1)*sizeof(char));

		val[numchars-1] = character;
		character = peek();
	}

	val[numchars] = '\0';

	int result = atoi(val);
	//printf("Read int from string %s (length %lu): %d\n)", val, strlen(val), result);
	addToken("int", val);

	free(val);
}

void readop(){
	character = pop();
	char* val = (char*) malloc(sizeof(char));
	val[0] = character;
	val[1] = '\0';
	addToken("op", val);
	//free(val);
	//return val;
}

void readIn(){
	character = peek();
	while(character != EOF){
		if(isdigit(character)){
			readint();
		}
		else if(character == '+' || character == '-'){
			readop();
		}
		else if(character == 'p'){
			char* val = (char*) malloc(sizeof(char)*7);
			for(int i = 0; i < 6; i++){
				val[i] = pop();
			}
			val[6] = '\0';
			addToken("please", val);
			//free(val);
		}
		else{
			pop();
		}
		character = peek();
	}
}



int main(void){
	//addToken("please", "please");
	//addToken("num", "1");
	//addToken("op", "+");
	//addToken("num", "1");

	// print out all tokens
	//printTokens();
	readIn();
	

	return 0;
}