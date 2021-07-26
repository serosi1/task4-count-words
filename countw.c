#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 15

void copy(char *str, char *strin, int i);
void count(char *str[][n], int *num, int N);
void sort(char *str[][n], int *num, int N);
void prnt(char *str[][n], int *num, int N);

int main(int argc, char **argv) {
	FILE *file;
	file = fopen(argv[1], "r");
	char arr[300];
	char *sym = " ~!@#%^&*()-+=:;\"\'<>,.?|{}[]";
	char *str[100][n];
	char *strin;
        int num[100];
	int i = 0;
	while (fgets(arr, 300, file) != NULL) {
		for(strin = strtok(arr, sym); strin != NULL; strin = strtok(NULL, sym)) {
			str[i][n] = malloc(strlen(strin));
			copy(str[i][n], strin, 0);
			i++;
		}
		i--;
	}
	count(str, num, i);
	sort(str, num, i);
	prnt(str, num, i);

	fclose(file);
	return 0;
}

void copy(char *str, char *strin, int i) {
	for(int j = 0; j < strlen(strin); i++, j++)
		str[i] = strin[j];
}

void count(char *str[][n], int *num, int N) {
	for(int i = 0; i < N; i++) {
		num[i] = 0;
		for(int j = 0; j < N; j++)
			if (strcasecmp(str[i][n], str[j][n]) == 0) 
				num[i]++;
	}
}

void sort(char *str[][n], int *num, int N) {
	char *st;
	int nu;
	for(int i = 0; i < N-1; i++) {
        	for(int j = 0; j < N-i-1; j++)
         		if (num[j] < num[j+1]) {
         			nu = num[j];
              			num[j] = num[j+1];
             	 		num[j+1] = nu;
				st = str[j][n];
				str[j][n] = str[j+1][n];
				str[j+1][n] = st;
         	 	}             
	 }
}

void prnt(char *str[][n], int *num, int N) {
	for(int i = 0; i < N; i++) {
		if (num[i] < 2) 
			break;
		int k = 0;
		for(int j = 0; (j < i) && (k < 1); j++)
			if (strcasecmp(str[i][n], str[j][n]) == 0)
				k++;
		if (k == 0) 
			printf("%-12s %d\n", str[i][n], num[i]);
	}
}	
