#define _CRT_SECURE_NO_WARNINGS
#define SIZE 6
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int size);
void printArr(int* arr, int size);

int main() {
    int arr[SIZE], i;
    printf("Input number:\n");
    for (i = 0; i < SIZE; ++i) { scanf("%d", &arr[i]); }
    bubbleSort(arr, SIZE);
    return 0;
}

void printArr(int* arr, int size) {
    int i;
    for (i = 0; i < size; ++i) { printf("%d ", *(arr + i)); }
    printf("\n");
}

void bubbleSort(int* arr, int size) {
    int i, j;
    for (i = 0; i < 5; ++i) {
        int temp;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Pass %d\n", i + 1);
        printArr(arr, size);
    }

}