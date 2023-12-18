#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> 
int f(int n) {
	if (n == 0) {
		return 0;
	}
	else if ((n == 1)||(n==2)) {
		return 1;
	}
	else {
		return f(n - 1) + f(n - 2);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", f(n));
}


	