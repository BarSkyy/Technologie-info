#include <iostream>
#include <cstring>

void usage(char *programName) {
    printf("Usage: %s number1 operation number2\n", programName);
    printf("Avaliable operations: \n");
    printf("\tadd\n");
    printf("\tminus\n");
    printf("\ttimes\n");
    printf("\tdevided\n");
    printf("\n");
}

int main(int argc, char *argv[]) {
    int number1 = 0;
    int number2 = 0;
    int result = 0;
    if (argc == 4) {
        number1 = atoi(argv[1]);
        number2 = atoi(argv[3]);
        if (!strcmp("add", argv[2])) {
            result = number1 + number2;
            printf("%d+%d=%d\n", number1, number2, result);
            return 0;
        }
        if (!strcmp("minus", argv[2])) {
            result = number1 - number2;
            printf("%d-%d=%d\n", number1, number2, result);
            return 0;
        }
        if (!strcmp("times", argv[2])) {
            result = number1 * number2;
            printf("%d*%d=%d\n", number1, number2, result);
            return 0;
        }
        if (!strcmp("devided", argv[2])) {
            if (number1 != 0 && number2 != 0) {
                result = number1 / number2;
                printf("%d/%d=%d\n", number1, number2, result);
                return 0;
            } else printf("Nie dziel przez zero!\n");
            return 0;
        }
    }
    usage(argv[0]);
    return 0;
}
