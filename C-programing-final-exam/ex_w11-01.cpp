#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>

int main() {
	FILE* fptr;
	fptr = fopen("input.txt", "r");
	FILE* fout;
	fout = fopen("output.txt", "w");
	char ch;
	char a = getc(fptr);
	if (fptr != NULL) {
		if (a == '*') {
			getc(fptr);
			while ((ch = getc(fptr)) != EOF) {
				if (ch > 64 && ch < 91) {
					fprintf(fout, "% c", ch + 32);
				}
				else if (ch > 60 && ch < 123) {
					fprintf(fout, "% c", ch - 32);
				}
				else {
					fputc('*', fout);
				}
			}
		}
		else {
			printf("erorr");
		}
	}
	else {
		printf("error");
	}
	fclose(fout);
	return 0;
}