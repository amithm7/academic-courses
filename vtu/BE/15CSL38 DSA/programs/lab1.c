#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

void create_array(int a[], int n) {
	int i;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

void display_array(int a[], int n) {
	int i;
	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}

int insert_at_pos(int item, int a[], int n, int pos) {
	int i;
	if(pos > n || pos < 0) {
		printf("Invalid position\n");
		return n;
	}
	for(i = n - 1; i >= pos; i--) {
		a[i + 1] = a[i];
	}
	a[pos] = item;
	return n + 1;
}

int delete_at_pos(int a[], int n, int pos) {
	int i;
	if(pos >= n || pos < 0) {
		printf("Invalid position\n");
		return n;
	}
	printf("Deleted element is %d\n", a[pos]);
	for(i = pos + 1; i < n; i++) {
		a[i - 1] = a[i];
	}
	return n - 1;
}

void main() {
	int ch, a[10], n, item, pos;
	//clrscr();
	for(;;)	{
		printf("Enter 1.Create 2. Display 3. Insert 4. Delete 5. Exit\n");
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1: printf("Enter the no. of element\n");
				scanf("%d", &n);
				printf("Enter %d elements\n", n);
				create_array(a, n); break;
			case 2: printf("The content of the array\n");
				display_array(a, n); break;
			case 3: printf("Enter the item to be inserted\n");
				scanf("%d", &item);
				printf("Enter the position to insert\n");
				scanf("%d", &pos);
				n = insert_at_pos(item, a, n, pos); break;
			case 4: printf("Enter the position of an item to be deleted\n");
				scanf("%d", &pos);
				n = delete_at_pos(a, n, pos);
				break;
			default: exit(0);
		}
	}
}
