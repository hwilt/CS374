/* Scanner Rule
  expr: term addsub term 
      | term addsub term addsub expr
      | term
  term: factor muldiv factor
      | factor muldiv factor muldiv term
      | factor
  factor: num
        | "(" expr ")"
  addsub: "+" | "-"
  muldiv: "*" | "/"
  num: [0-9]+
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char token;
int expr(void);

char pop(){
	char ch = getchar();
	printf("Popped %c\n", ch);
	return ch;
}

char peek(){
	char ch = pop();
	ungetc(ch, stdin);
	printf("Pushed %c\n", ch);
	return ch;
} 


int readint(){
	int numchars = 0;
	char* val = (char*) malloc(sizeof(char));

	token = peek();
	while(isdigit(token)){
		pop();

		numchars++;
		val = (char*) realloc(val, (numchars+1)*sizeof(char));

		val[numchars-1] = token;
		token = peek();
	}

	val[numchars] = '\0';

	int result = atoi(val);
	printf("Read int from string %s (length %lu): %d\n)", val, strlen(val), result);

	free(val);
	return result;
}


int factor(){
	printf("In factor\n");

	int value;
	token = peek();

	if(token == '('){
		pop();
		value = expr();
		token = pop();
		if(token != ')'){
			printf("Error: Imbalance of Paranthesis\n");
			exit(-1);
		}
	} else if(isdigit(token)){
		value = readint();
	} else {
		printf("Error: Invalid token %c\n", token);
	}

	printf("Factor value: %d\n", value);
	return value;
}

int term(){
	printf("In term\n");
	int value = factor();
	token = peek();

	if (token == '*'){
		pop();
		value *= factor();
	}
	else if (token == '/'){
		pop();
		value /= factor();
	}

	token = peek();

	if (token == '*'){
		pop();
		value *= term();
	}
	else if (token == '/'){
		pop();
		value /= term();
	}

	printf("Term value: %d\n", value);

	return value;

}

int expr(){
	printf("In expr\n");

	// get the madatory first term
	int value = term();
	token = peek();

	// now handle the optional second term
	if (token == '+'){
		pop();
		value += term();
	}
	else if (token == '-'){
		pop();
		value -= term();
	}

	token = peek();

	// now handle the optional third expression
	if (token == '+'){
		pop();
		value += expr();
	}
	else if (token == '-'){
		pop();
		value -= expr();
	}

	printf("Expression value: %d\n", value);
	return value;
}



int main(void) {
	token = peek();
	int result = expr();
	printf("Result: %d\n", result);
	return 0;
}