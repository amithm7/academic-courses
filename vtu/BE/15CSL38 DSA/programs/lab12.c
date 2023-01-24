#include <stdio.h>
#include <stdlib.h>

int key[20], n, m;
int *ht, hashindex;
int elecount = 0;

void createHashTable() {
	int i;
	ht = (int*) malloc(m * sizeof(int));
	if(ht == NULL)
		printf("Unable to create the hash table");
	else
		for(i = 0; i < m; i++)
			ht[i] = -1;
}

void insertIntoHashTable(int key) {
	hashindex = key % m;
	while(ht[hashindex] != -1) {
		hashindex = (hashindex + 1) % m;
	}
	ht[hashindex] = key;
	elecount++;
}

void displayHashTable() {
	int i;
	if(elecount == 0) {
		printf("Hash table is empty\n");
		return;
	}
	printf("Hash table contents are:\n");
	for(i = 0; i < m; i++)
		printf("T[%d] --> %d\n", i, ht[i]);
}

void main() {
	int i;
	printf("Enter the number of employee records(N): ");
	scanf("%d", &n);
	printf("Enter the four digit values (K) of 'N' Employee Records:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &key[i]);
	printf("Enter the two digit memory locations(m) for hash table: ");
	scanf("%d", &m);
	createHashTable();
	printf("Inserting key values of employee records into hash table....\n");
	for(i = 0; i < n; i++) {
		if(elecount == m) {
			printf("Hash table is full. Cannot insert the %d record key value", i);
			break;
		}
		insertIntoHashTable(key[i]);
	}
	displayHashTable();
}
