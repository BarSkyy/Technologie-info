#include <iostream>
#include "functions.h"
#define SIZE 10
using namespace std;

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("array[%d]=%d\n", i, array[i]);
    }
}

void menu(void) {

    printf("1. Enter the value into the array\n");
    printf("2. Display the content of the array\n");
    printf("3. Determine the minimum value\n");
    printf("4. Determine the maximum value\n");
    printf("5, Determine the average value\n");
    printf("0. EXIT\n");
    printf("Select an option:\n");
};

int main() {
    int array[SIZE] = {1, 2, 3, -4, 50, 6, 7, 8, 9, 10};
    int option = 0;
    printf("***SIMPLE ARRAY***\n\n");
    do {
        menu();
        scanf("%d", &option);
        switch (option) {
            case 0:
                break;
            case 1:
                printf("Entering values into the array\n\n");
                break;
            case 2:
                printArray(array, SIZE);
                break;
            case 3:
                printf("Determining the minimum value\n\n");
                printf("Min: %d\n", findMin(array, SIZE));
                break;
            case 4:
                printf("Determining the maximum value\n\n");
                printf("Max: %d\n", findMax(array,SIZE));
                break;
            case 5:
                printf("Determining the average value\n\n");
                printf("Avg: %.2f\n", findAvg(array,SIZE));
                break;
            default:
                printf("Choose the right option...\n\n");
        }
    } while (option != 0);
    printf("THE END!\n");
    return 0;
}
