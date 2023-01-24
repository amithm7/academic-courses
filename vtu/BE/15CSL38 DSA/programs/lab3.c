#include <stdio.h>
// #include <conio.h>

#define STACK_SIZE 5

int item, top, s[10];
char str[20];
top = -1;

void push () {
	if (top == STACK_SIZE - 1) {
		printf ("Stack Overflow!\n");
		return;
	}
	top = top + 1;
	s[top] = item;
}

void pop () {
	if (top == -1) {
		printf ("Stack Underflow!\n");
		return;
	}
	printf ("The deleted item from the stack is %d\n", s[top]);
	top = top - 1;
}

void display () {
	int i;
	if (top == -1) {
		printf ("Stack Underflow!\n");
		return;
	}
	printf ("The contents of stacks\n");
	for (i = 0; i <= top; i++) {
		printf ("%d\n", s[i]);
	}
}

int is_palindrome (char str[]) {
	int i, top;
	char s[10], stk_item;
	top = -1;
	for (i = 0; i < strlen(str); i++) {
		s[++top] = str[i];
	}
	for (i = 0; i < strlen(str); i++) {
		if (str[i] != s[top--])
			return 0;
	}
	return 1;
}

void main() {
	int ch, flag;
	// clrscr();
	top = -1;   // Empty stack

	for (;;) {
		printf ("Enter 1: Push 2: Pop 3: Display 4: Palindrome 5: Exit\n");
		printf ("Enter your choice\n");
		scanf ("%d", &ch);

		switch(ch) {
			case 1: printf ("Enter the item to be inserted\n");
					scanf ("%d", &item);
					push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: printf ("Enter string to check for palindrome\n");
					scanf ("%s", str);
					flag = is_palindrome (str);
					if (flag == 0)
						printf ("The string is not a palindrome\n");
					else
						printf ("The string is a palindrome\n");
					break;
			default: exit(0);
		}
	}
	// getch();
}
