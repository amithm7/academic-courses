#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node {
	int USN, SEM, PHNO;
	char NAME[20], BRANCH[10];
	struct node *link;
};

typedef struct node *NODE;

NODE first  = NULL;
int count = 0;
int usn, sem, phno;
char name[20], branch[10];

NODE insert_front() {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));

	printf("Enter the student details:\n");
	printf("USN\tNAME\tBRANCH\tSEM\tPHNO\n");
	scanf("%d%s%s%d%d", &usn, name, branch, &sem, &phno);

	temp->USN = usn;
	strcpy(temp->NAME, name);
	strcpy(temp->BRANCH, branch);
	temp->SEM = sem;
	temp->PHNO = phno;

	temp->link = first;
	count++;

	return temp;
}

void create() {
	int i, n;
	printf("Enter number of students\n");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		first = insert_front();
	}
}

NODE delete_front() {
	NODE temp;

	if(first == NULL) {
		printf("List is empty\n");
		return first;
	}

	temp = first;
	temp = temp->link;

	printf("Student usn = %d, name = %s\n", first->USN, first->NAME);

	free(first);
	count--;

	return temp;
}

NODE insert_rear() {
	NODE temp;
	NODE cur;

	temp = (NODE) malloc(sizeof(struct node));
	printf("Enter the student details:\n");
	printf("USN\tNAME\tBRANCH\tSEM\tPHNO\n");

	scanf("%d%s%s%d%d", &usn, name, branch, &sem, &phno);

	temp->USN = usn;
	strcpy(temp->NAME, name);
	strcpy(temp->BRANCH, branch);
	temp->SEM = sem;
	temp->PHNO = phno;
	temp->link = NULL;

	if(first == NULL) {
		count++;
		return temp;
	}

	cur = first;
	while(cur->link != NULL) {
		cur = cur->link;
	}
	cur->link = temp;
	count++;
	return first;
}

NODE delete_rear() {
	NODE temp, cur, prev;
	if(first == NULL) {
		printf("List is empty\n");
		return first;
	}

	if(first->link == NULL) {
		printf("%d\t%s\n", first->USN, first->NAME);
		count--;
		free(first);
		return NULL;
	}

	prev = NULL;
	cur = first;

	while(cur->link != NULL) {
		prev = cur;
		cur = cur->link;
	}

	printf("Student usn = %d, name = %s\n", cur->USN, cur->NAME);
	free(cur);

	prev->link = NULL;
	count--;
	return first;
}

void display() {
	NODE temp;
	if(first == NULL) {
		printf("List is empty\n");
		return;
	}

	printf("The contents of singly linked list: \n");
	temp = first;

	while(temp != NULL) {
		printf("%d\t%s\t%s\t%d\t%d\n", temp->USN, temp->NAME, temp->BRANCH, temp->SEM, temp->PHNO);
		temp = temp->link;
	}

	printf("The number of nodes in the SLL = %d\n", count);
}

void main() {
	int choice;
	for(;;) {
		//clrscr();
		printf("\n1.Create \t2.Display\n");
		printf("3.Insert_rear \t4.Delete_rear\n");
		printf("Demonstration of stack-\n5.Insert_front(push), 6.Delete_front(pop)");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice) {
			case 1: create();
				break;
			case 2: display();
				break;
			case 3: first = insert_rear();
				break;
			case 4: first = delete_rear();
				break;
			case 5: printf("Push \n");
				first = insert_front();
				break;
			case 6:	printf("Pop \n");
				first = delete_front();
				break;
			default: printf("Invalid choice\n");
				exit(0);
		}
	}
}
