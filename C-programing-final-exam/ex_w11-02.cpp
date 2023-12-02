#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>

int main() {
	FILE* fptr;
	fptr = fopen("ex2_input.txt", "r");
	int c = 0, s = 0;
	if (fptr != NULL) {
		fscanf(fptr, "%d", &s);
		fscanf(fptr, "%d", &c);
		if (s == 1) {
			for (int i =c;i>0;i--){
				for (int j =i; j > 0; j--) {
					printf("* ");
				}
				printf("\n");
			}
		}
		else if (s == 2) {
			for (int i = c; i > 0; i--) {
				for (int j = i- 1; j >= 0; j--) {
					printf(" ");
				}
				for (int k =0;  k <= c - i; k++) {
					printf("* ");
				}
				printf("\n");
			}
		}
		else if (s == 3) {
			for (int i = c; i > 0; i--) {
				for (int j =i-1 ; j > 0; j--) {
					printf("  ");
				}
				for (int k = 0; k <= 5 - i; k++) {
					printf("* ");
				}
				printf("\n");
			}
		}

	}
	else {
		printf("error");
	}
	return 0;
}