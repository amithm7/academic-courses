#include <stdlib.h>
#include <stdio.h>
#define Q_SIZE 5

int item, front, rear, count, Q[Q_SIZE];

void insertCQ() {
	if(count == Q_SIZE) {
		printf("Q full\n");
		return;
	}
	rear = (rear + 1) % Q_SIZE;
	Q[rear] = item;
	count++;
}

int deleteCQ() {
	int item;
	if(count == 0) return -1;
	item = Q[front];
	front = (front + 1) % Q_SIZE;
	count -= 1;
	return item;
}

void display() {
	int i, f;
	if(count == 0) {
		printf("Q is empty\n");
		return;
	}
	printf("The contents of the C Queue:\n");
	for(i = 1, f = front; i <= count; i++) {
		printf("%d\n", Q[f]);
		f = (f + 1) % Q_SIZE;
	}
}

void main() {
	// clrscr();
	int ch, front = 0; rear = -1; count = 0;
	for(;;) {
		printf("1. Insert 2. Delete 3. Display 4. Exit\n");
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("Enter item\n");
				scanf("%d", &item);
				insertCQ();
				break;
			case 2:
				item = deleteCQ();
				if(item == -1) {
					printf("Q is empty\n");
					break;
				}
				printf("Item deleted = %d\n", item);
				break;
			case 3:
				display();
				break;
			default:
				exit(0);
		}
	}
}
