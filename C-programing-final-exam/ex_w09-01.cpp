#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>

int main() {
    int* array = (int*)malloc(sizeof(int)); // Initialize the array size to be 1*sizeof(int)
    int size = 1;
    int n = 0; // Number of elements in the array

    if (array == NULL) {
        return 1;
    }

    while (1) {
        int action;
        printf("Enter your action : ");
        scanf("%d", &action);

        if (action == 0) {
            break; // Quit the program
        }
        else if (action == 1) {
            int element;
            printf("Enter the element to add: ");
            scanf("%d", &element);

            if (n >= size) {
                // Double the size of the array if it's not enough
                size *= 2;
                array = (int*)realloc(array, size * sizeof(int));
                if (array == NULL) {
                    return 1;
                }
            }

            array[n] = element;
            n++;
        }
        else if (action == 2) {
            if (n > 0) {
                // Remove the last element and set it to -7777
                array[n - 1] = -7777;
                n-=1;

                // Reduce array size if the number of elements is less than or equal to half of the size
                if (n <= size / 2) {
                    size /= 2;
                    array = (int*)realloc(array, size * sizeof(int));
                    if (array == NULL) {
                        return 1;
                    }
                }
            }
            else {
                printf("Array is empty. Cannot remove an element.\n");
            }
        }

        // Print the whole array
        printf("Current array: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    free(array); // Free the dynamically allocated memory
    return 0;
}
