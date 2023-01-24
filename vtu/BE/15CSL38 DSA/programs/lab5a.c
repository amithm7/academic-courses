#include <stdio.h>
#include <ctype.h>
//#include <conio.h>
#include <math.h>
#include <string.h>

double compute(char symbol, double op1, double op2) {
	switch(symbol) {
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		case '%': return (int)op1 % (int)op2;
		case '$':
		case '^': return pow(op1, op2);
		default : printf("Invalid operation\n");
	}
}

void main() {
	double s[20], res, op1, op2; int i, top;
	char postfix[30], symbol;
	//clrscr();
	printf("Enter the postfix expression\n");
	scanf("%s", postfix);
	top = -1;
	for(i = 0; i < strlen(postfix); i++) {
		symbol = postfix[i];
		if(isdigit(symbol))
			s[++top] = symbol - '0';
		else {
			op2 = s[top--];
			op1 = s[top--];
			res = compute(symbol, op1, op2);
			s[++top] = res;
		}
	}
	// s[++top] = res; ?
	printf("The result is %f\n", res);
	//getch();
}
