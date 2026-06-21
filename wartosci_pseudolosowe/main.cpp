#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));
    int min = 0;
    int max = 0;
    int amount = 0;
    printf("Specify min-max range\n");
    printf("Pick min value: ");
    scanf("%d", &min);
    printf("Pick max value: ");
    scanf("%d", &max);
    printf("Pick an amount of drawn values: ");
    scanf("%d", &amount);
    int *temps;
    temps = (int *) malloc(amount * sizeof(int));
    if (temps == NULL) {
        printf("ERROR!\n");
        return 1;
    }
    if (max >= min) {
        for (int i = 0; i < amount; i++) {
            *temps = (rand() % (max - min + 1)) + min;
            printf("\nDrawn value: %d", *temps);
        }
    } else
        printf("\nError! Min value can't be higher than max!\n");
    free(temps);
    return 0;
}
