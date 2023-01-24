#include <stdio.h>
#include <stdlib.h>

struct node {
	int cf, px, py, pz, flag;
	struct node *link;
};

typedef struct node *NODE;

NODE getnode() {
	NODE x;
	x = (NODE) malloc(sizeof(struct node));
	if(x == NULL) {
		printf("insufficient memory\n");
		exit(0);
	}
	return x;
}

NODE insert_rear(int cf, int px, int py, int pz, NODE head) {
	NODE temp, cur;
	temp = getnode();
	temp->cf = cf;
	temp->px = px;
	temp->py = py;
	temp->pz = pz;
	temp->flag = 0;
	cur = head->link;
	while(cur->link != head) {
		cur = cur->link;
	}
	cur->link = temp;
	temp->link = head;
	return head;
}

NODE read_poly(NODE head) {
	int m, i, cf, px, py, pz;
	printf("Enter the number of terms\n");
	scanf("%d", &m);

	for(i = 1; i <= m; i++) {
		printf("Enter the coff, power of x, y and z\n");
		scanf("%d%d%d%d", &cf, &px, &py, &pz);
		head = insert_rear(cf, px, py, pz, head);
	}
	return head;
}

void display_poly(NODE head) {
	NODE cur;
	cur = head->link;
	while(cur != head) {
		if(cur->cf > 0) {
			printf("+%d(", cur->cf);
		} else {
			printf("%d(", cur->cf);
		}
		if(cur->px > 0)
			printf("x^%d ", cur->px);
		if(cur->py > 0)
			printf("y^%d ", cur->py);
		if(cur->pz > 0)
			printf("z^%d) ", cur->pz);
		cur = cur->link;
	}
	printf("\n");
}

NODE add_poly(NODE h1, NODE h2, NODE h3) {
	NODE c1, c2;	// current trackers
	int c, px1, py1, pz1, px2, py2, pz2;
	c1 = h1->link;

	while(c1 != h1) {
		px1 = c1->px, py1 = c1->py, pz1 = c1->pz;

		c2 = h2->link;
		while(c2 != h2) {
			px2 = c2->px, py2 = c2->py, pz2 = c2->pz;

			if (px1 == px2 && py1 == py2 && pz1 == pz2) {
				c = c1->cf + c2->cf;
				h3 = insert_rear(c, px2, py2, pz2, h3);
				c2->flag = 1;
				break;
			}

			c2 = c2->link;
			if(c2 == h2)
				h3 = insert_rear(c1->cf, c1->px, c1->py, c1->pz, h3);
		}
		c1 = c1->link;
	}

	c2 = h2->link;
	while (c2 != h2) {
		if(c2->flag == 0)
			h3 = insert_rear(c2->cf, c2->px, c2->py, c2->pz, h3);
		c2 = c2->link;
	}

	return h3;
}

void main() {
	NODE h1, h2, h3;
	h1 = getnode();
	h1->link = h1;
	h2 = getnode();
	h2->link = h2;
	h3 = getnode();
	h3->link = h3;
	printf("first poly\n");
	h1 = read_poly(h1);
	printf("Second poly\n");
	h2 = read_poly(h2);
	h3 = add_poly(h1, h2, h3);
	printf("first poly\n");
	display_poly(h1);
	printf("Second poly\n");
	display_poly(h2);
	printf("Sum of two poly\n");
	display_poly(h3);
}
