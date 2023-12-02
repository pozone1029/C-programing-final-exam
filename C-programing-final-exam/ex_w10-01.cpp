#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>
void printArrays(int** A, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < A[i][0]; j++) {
			printf("%d ", A[i][j + 1]);
		}
		printf("\n");
	}
}

int main() {
	int** A;
	int N;
	printf("input N:");
	scanf("%d", &N);
	printf("step 1:\n");								//step 1
	printf("input N numbers:");
	A = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++) {
		int column;
		scanf("%d", &column);
		A[i] = (int*)calloc(column+1, sizeof(int));
		A[i][0] = column;								//stored the column number in first element 
		for (int j = 1; j <= column; j++) {
			A[i][j] = 0;								//initialize all element to 0
		}
	}
	printArrays(A, N);

	printf("step 2:\n");								//step 2
	printf("input R and S:");
	int R, S;
	scanf("%d %d", &R, &S);
	if (R >= 0 && R <= N) {
		A[R-1] = (int*)realloc(A[R-1], (S + 1) * sizeof(int));
		if (S > A[R-1][0]) {
			for (int j = A[R-1][0]+1; j <= S; j++) {
				A[R-1][j] = 1;
			}
		}
		A[R-1][0] = S;									//change column numbers
	}
	printArrays(A, N);
	printf("step 3:\n");								//step 3
	printf("input N2:");
	int N2;
	scanf("%d", &N2);
	A = (int**)realloc(A, N2 * sizeof(int*));
	for (int i = N; i < N2; i++) {
		A[i] = (int*)calloc(3, sizeof(int));
		A[i][0] = 2;
		A[i][1] = 2;
		A[i][2] = 2;
	}
	N = N2;												//change N
	printArrays(A, N);

	printf("step 4:\n");							   //step 4
	printf("input D:");
	int D;
	scanf("%d", &D);
	if (D >= 0 && D < N) {
		free(A[D-1]);
		for (int i = D-1; i < N - 1; i++) {
			A[i] = A[i + 1];
		}
		N--;											//change N
		A = (int**)realloc(A, N * sizeof(int*));
	}
	printArrays(A, N);
	return 0;
}