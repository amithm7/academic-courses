#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *llink, *rlink;
};

typedef struct node *NODE;

NODE troot;

void inorder(NODE troot) {
	if(troot != NULL) {
		inorder(troot->llink);
		printf("%d\t", troot->info);
		inorder(troot->rlink);
	}
}

void preorder(NODE troot) {
	if(troot != NULL) {
		printf("%d\t", troot->info);
		preorder(troot->llink);
		preorder(troot->rlink);
	}
}

void postorder(NODE troot) {
	if(troot != NULL) {
		postorder(troot->llink);
		postorder(troot->rlink);
		printf("%d\t", troot->info);
	}
}

void insert(int item) {
	NODE temp, cur, prev;
	temp = (NODE)malloc(sizeof(struct node));
	temp->llink = temp->rlink = NULL;
	temp->info = item;
	if(troot == NULL) {
		troot = temp;
		return;
	} else {
		prev = NULL;
		cur = troot;
		while(cur != NULL) {
			prev = cur;
			if(item < cur->info)
				cur = cur->llink;
			else
				cur = cur->rlink;
		}
		if(item < prev->info)
			prev->llink = temp;
		else
			prev->rlink = temp;
	}
}

void createtree() {
	int i, n, item;
	printf("Enter the number of elements:");
	scanf("%d", &n);
	printf("Enter %d elements:\n", n);
	for(i = 0; i < n; i++) {
		scanf("%d", &item);
		insert(item);
	}
}

void search(int item, NODE troot) {
	NODE cur;
	int found;
	if(troot == NULL)
		printf("Tree is empty\n");
	cur = troot;
	while(cur != NULL) {
		if(item == cur->info) {
			found = 1;
		}
		if(found == 1)
			break;
		if(item < cur->info)
			cur = cur->llink;
		else
			cur = cur->rlink;
	}
	if(found != 1)
		printf("UnSuccessful search\n");
	else
		printf("Successful search");
}

int main() {
	int key, ele;
	int ch;

	while(1) {
		printf("\nMenu\n1.Insert\t2.inorder\t3.preorder\t4.postorder\n5.Search\t6.Exit\n");
		printf("Enter the choice:");
		scanf("%d", &ch);

		switch(ch) {
			case 1:
				createtree();
				break;
			case 2:
				inorder(troot);
				break;
			case 3:
				preorder(troot);
				break;
			case 4:
				postorder(troot);
				break;
			case 5:
				printf("Enter the key element to be searched\n");
				scanf("%d", &key);
				search(key, troot);
				break;
			default: exit(0);
		}
		// getch();
	}
}
