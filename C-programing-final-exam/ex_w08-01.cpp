#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> 

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 97; i < (n + 97); i++) {
		printf("%c", i);
	}
	return 0;
}