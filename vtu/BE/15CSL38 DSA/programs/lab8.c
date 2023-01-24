#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int SSN, SAL, PHNO;
	char NAME[20], DEPT[10], DESG[10];
	struct node *rlink;
	struct node *llink;
};

typedef struct node *NODE;

NODE first = NULL;
int count = 0;
int ssn, sal, phno;
char name[20], dept[10], desg[10];

NODE insert_end() {
	NODE temp, cur;
	temp = (NODE)malloc(sizeof(struct node));
	printf("Enter the employee details:\n");
	printf("SSN\tNAME\tDEPT\tDESG\tSAL\tPHNO\n");
	scanf("%d%s%s%s%d%d", &ssn, name, dept, desg, &sal, &phno);

	temp->SSN = ssn;
	strcpy(temp->NAME, name);
	strcpy(temp->DEPT, dept);
	strcpy(temp->DESG, desg);
	temp->SAL = sal;
	temp->PHNO = phno;
	temp->llink = temp->rlink = NULL;

	if (first == NULL) {
		count++;
		return temp;
	}

	cur = first;
	while (cur->rlink != NULL) {
		cur = cur->rlink;
	}
	cur->rlink = temp;
	temp->llink = cur;
	temp->rlink = NULL;
	count++;
	return first;
}

NODE insert_front() {
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));

	printf("Enter the employee details:\n");
	printf("SSN\tNAME\tDEPT\tDESG\tSAL\tPHNO\n");
	scanf("%d%s%s%s%d%d", &ssn, name, dept, desg, &sal, &phno);

	temp->SSN = ssn;
	strcpy(temp->NAME, name);
	strcpy(temp->DEPT, dept);
	strcpy(temp->DESG, desg);
	temp->SAL = sal;
	temp->PHNO = phno;

	temp->llink = NULL;
	temp->rlink = first;
	first->llink = temp;
	count++;
	return temp;
}

void create() {
	int i, n;

	printf("Enter the number of employees\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++){
		first = insert_end();
	}
}

NODE delete_front() {
	NODE temp;

	if (first == NULL)
	{
		printf("List is empty\n");
		return first;
	}

	temp = first->rlink;
	temp->llink = NULL;

	printf("Employee ssn = %d, name = %s\n", first->SSN, first->NAME);

	free(first);
	count--;

	return temp;
}

NODE delete_end() {
	NODE temp, cur, prev;
	if (first == NULL)
	{
		printf("List is empty\n");
		return first;
	}

	if (first->rlink == NULL)
	{
		printf("Employee ssn = %d, name = %s\n", first->SSN, first->NAME);
		count--;
		free(first);
		return NULL;
	}

	prev = NULL;
	cur = first;

	while (cur->rlink != NULL)
	{
		prev = cur;
		cur = cur->rlink;
	}

	printf("Employee ssn = %d, name = %s\n", cur->SSN, cur->NAME);
	free(cur);

	prev->rlink = NULL;
	count--;
	return first;
}

void display() {
	NODE temp;
	if (first == NULL)
	{
		printf("List is empty\n");
		return;
	}

	printf("The contents of doubly linked list: \n");
	temp = first;

	while (temp != NULL)
	{
		printf("%d\t%s\t%s\t%s\t%d\t%d\n", temp->SSN, temp->NAME, temp->DEPT, temp->DESG, temp->SAL, temp->PHNO);
		temp = temp->rlink;
	}

	printf("The number of nodes in the SLL = %d\n", count);
}

int main() {
	int choice;

	for(;;) {
		printf("\n1.Create N employee data\t2.Display\n");
		printf("3.Insert_end\t4.Delete_end\n");
		printf("5.Insert_front\t6.Delete_front\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);

		switch(choice) {
			case 1: create(); break;
			case 2: display(); break;
			case 3: first = insert_end(); break;
			case 4: first = delete_end(); break;
			case 5: first = insert_front(); break;
			case 6: first = delete_front(); break;
			default: printf("Exit\n"); exit(0);
		}
	}
}
