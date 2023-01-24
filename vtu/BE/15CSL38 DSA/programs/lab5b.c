#include <stdio.h>
#include <stdlib.h>

void tower(int n, char s, char t, char d) {
	if (n == 0) return;
	tower(n-1, s, d, t);
	printf("Move disc %d from %c to %c\n", n, s, d);
	tower(n-1, t, s, d);
}

void main() {
	int n;
	// clrscr();
	printf("Enter the number of disks\n");
	scanf("%d", &n);
	tower(n, 'A', 'B', 'C');
	// getch();
}
