#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>
int** matrix_multiplication(int** mat1, int** mat2, int m, int n, int p) {
	int** cmp = (int**)calloc(m, sizeof(int*));
	for (int i = 0; i <= m-1; i++) {
		cmp[i]= (int*)calloc(p, sizeof(int));
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			cmp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				cmp[i][j]+=mat1[i][k] * mat2[k][j];
				
			}
			
		}
	}
	return cmp;
}
int main() {
	int m, n, p;
	int** mat1=NULL;
	int** mat2=NULL;
	scanf("%d %d %d", &m, &n, &p);
	printf("\n");
	mat1 = (int**)calloc(m, sizeof(int*));
	for (int i = 0; i <= m-1; i++) {
		mat1[i] = (int*)calloc(n, sizeof(int));
	}
	mat2 = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i <= n-1; i++) {
		mat2[i] = (int*)calloc(p, sizeof(int));
	}
	for (int i = 0; i < m; i++) {
		for (int j=0; j < n; j++) {
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			scanf("%d",&mat2[i][j]);
		}
	}
	printf("\n");
	int** result =matrix_multiplication(mat1, mat2, m, n, p);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}