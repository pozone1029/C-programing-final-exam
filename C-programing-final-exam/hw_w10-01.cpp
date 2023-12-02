#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>
#include <string.h>
void printArrays(char** A, char** B, int m, int n) {
	printf("A:\n");
	for (int i = 0; i < m; i++) {
		if (A[i] != NULL) {
			printf("%s\n", A[i]);
		}
		else {
			printf("(null)\n");
		}
	}
	printf("\n");
	printf("B:\n");
	for (int i = 0; i < n; i++) {
		if (B[i] != NULL) {
			printf("%s\n", B[i]);
		}
		else {
			printf("(null)\n");
		}
	}
	printf("\n");
}
int main() {
	char** A = NULL;
	char** B = NULL;
	int m, n, p;
	scanf("%d %d", &m, &n);
	printf("\n");
	A = (char**)calloc(m, sizeof(char*));
	B = (char**)calloc(n, sizeof(char*));
	while (1) {
		scanf("%d", &p);
		printf("\n");
		if (p == 0) {												//p=0 intput name of book
			int x, y, s;
			scanf("%d %d %d", &x, &y, &s);
			if (x == 0) {
				A[y] = (char*)calloc(s, sizeof(char));
				scanf("%s", A[y]);
			}
			else if (x == 1) {
				B[y] = (char*)calloc(s, sizeof(char));
				scanf("%s", B[y]);
			}
			printArrays(A, B, m, n);
		}
		else if (p == 1) {													 //p=1
			int a, b;
			scanf("%d %d", &a, &b);
			if (a == 0) {
				if (b < m) {
					free(A[b]);
					A[b] = NULL;
					A = (char**)realloc(A, m * sizeof(char*));
				}
				else {
					break;
				}
			}
			else if (a == 1) {
				if (b < n) {
					free(B[b]);
					B[b] = NULL;
					n--;
					B = (char**)realloc(A, (n - 1) * sizeof(char*));
				}
				else {
					break;
				}

			}
			printArrays(A, B, m, n);
		}
		else if (p == 2) {										//p=2
			int c, d;
			scanf("%d %d", &c, &d);
			if (c < m && d < n) {
				int length_c = strlen(A[c]);
				int length_d = strlen(B[d]);
				char* transition = (char*)calloc(length_d, sizeof(char));
				strcpy(transition, B[d]);
				B[d] = (char*)realloc(B[d], (length_c + 1) * sizeof(char));
				strcpy(B[d], A[c]);
				A[c] = (char*)realloc(A[c], (length_d + 1) * sizeof(char));
				strcpy(A[c], transition);
				free(transition);
			}
			else {
				break;
			}
			printArrays(A, B, m, n);
		}
		else if (p == 3) {
			break;
		}
	}

	return 0;
}