# include <stdio.h>
//# include <conio.h>

void read_data();
void search_replace();

char str[100], pat[100], rep[100], update[100];

void main() {
	// clrscr();
	read_data();
	search_replace();
//	getch();
}

void read_data() {
	printf("Enter a string\n");
	gets(str);
	printf("Enter a search string\n");
	gets(pat);
	printf("Enter a replace string\n");
	gets(rep);
}

void search_replace() {
	int i = 0, j = 0, c = 0, m = 0, k, flag = 0;
	while(str[c] != '\0') {
		if(str[m] == pat[i]) {
			i++; m++;
			if (pat[i] == '\0') {
				flag = 1;
				for (k = 0; rep[k] != '\0'; k++, j++)
					update[j] = rep[k];
				i = 0;
				c = m;
			}
		}
		else {
			update[j] = str[c];
			j++; c++;
			m = c; i = 0;
		}
	}
	if(flag == 1) {
		update[j] = '\0';
		printf("The resultant string is %s\n", update);
	}
	else {
		printf("String not found\n");
	}
}
