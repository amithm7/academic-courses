#include <stdio.h>
#include <string.h>

int SP(char symbol) {	// Stack Precedence
	switch(symbol) {
		case '+':
		case '-': return 2;
		case '%':
		case '*':
		case '/': return 4;
		case '^':
		case '$': return 5;
		case '(': return 0;
		case '#': return -1;
		default: return 8;
	}
}

int IP(char symbol) {	// Input Precedence
	switch(symbol) {
		case '+':
		case '-': return 1;
		case '%':
		case '*':
		case '/': return 3;
		case '^':
		case '$': return 6;
		case '(': return 9;
		case ')': return 0;
		default: return 7;
	}
}

void infix_postfix(char infix[], char postfix[]) {
	int top, i, j;
	char symbol, s[30];
	top = -1;
	s[++top] = '#';
	j = 0;
	for(i = 0; i < strlen(infix); i++) {
		symbol = infix[i];
		while(SP(s[top]) > IP(symbol))
			postfix[j++] = s[top--];
		if(SP(s[top]) != IP(symbol))
			s[++top] = symbol;
		else
			top--;
	}
	while(s[top] != '#')
		postfix[j++] = s[top--];
	postfix[j] = '\0';
}

void main() {
	char infix[30], postfix[30];
	// clrscr();
	printf("Enter a valid infix expression\n");
	scanf("%s", infix);
	infix_postfix(infix, postfix);
	printf("The postfix expression is %s\n", postfix);
	// getch();
}
