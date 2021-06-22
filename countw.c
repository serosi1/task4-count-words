#include <stdio.h>
#include "stdlib.h"
#include <string.h>

void count(char *str[][15], int *num, int N);
void sort(char *str[][15], int *num, int N);
void prnt(char *str[][15], int *num, int N);

int main(int argc, char **argv) {
	FILE *file;
	file = fopen(argv[1], "r");
	char arr[300];
	char *str[100][15];
	char *str1;
        int num[100];
	int i = 1, N;
	fgets(arr, 300, file);
	str1 = strtok(arr, " ~!@#%^&*()-+=:;\"\'<>,.?|/\\{}[]");
	str[0][15] = str1;
	while(str1 != NULL) {
		str1 = strtok(NULL, " ~!@#%^&*()-+=:;\"\'<>,.?|/\\{}[]");
		str[i][15] = str1;
		i++;
	}
	N = i - 2;
	count(str, num, N);
	sort(str, num, N);
	prnt(str, num, N);

	fclose(file);
	return 0;
}

void count(char *str[][15], int *num, int N) {
	for(int i = 0; i < N; i++) {
		num[i] = 0;
		for(int j = 0; j < N; j++)
			if ((strcasecmp(str[i][15], str[j][15]) == 0)) 
				num[i]++; 
	}
}

void sort(char *str[][15], int *num, int N) {
	char *st;
	int nu;
	for(int i = 0; i < N-1; i++) {
        	for (int j = 0; j < N-i-1; j++)
         		if (num[j] < num[j+1]) {
         			nu = num[j];
              			num[j] = num[j+1];
             	 		num[j+1] = nu;
				st = str[j][15];
				str[j][15] = str[j+1][15];
				str[j+1][15] = st;
         	 	}             
	 }
}

void prnt(char *str[][15], int *num, int N) {
	for(int i = 0; i < N; i++) {
		if (num[i] <= 1) break;
		if (strcasecmp(str[i][15], str[i+1][15]) != 0)
			printf("%s %d\n", str[i][15], num[i]);
	}
}	
