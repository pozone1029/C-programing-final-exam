#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>
int* compare(const char* S, const char* T, int N) {
	int*cmp= (int*)calloc(N, sizeof(int));
	for (int i=0; i < N; i++) {
		if (S[i] == T[i]) {
			cmp[i] = 1;
		}
		else {
			cmp[i] = 0;
		}
	}
	return cmp;
}

int main() {
	int N;
	while (1) {
		scanf("%d", &N);
		if (N ==0) {
			break;
		}
		char* S = (char*)calloc(N, sizeof(char));
		char* T = (char*)calloc(N, sizeof(char));
		scanf("%s", S);
		scanf("%s",T);
		int* result = compare(S, T, N);
		for (int i = 0; i < N; i++) {
			printf("%d", result[i]);
		}
		free(result);
		printf("\n");
	}
	

}