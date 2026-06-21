#include <iostream>
#include "stack.h"

void menu(void) {
    printf("\n");
    printf("1 - wstaw liczbe do kolejki (Push)\n");
    printf("2 - odczytaj wartosc z poczatku kolejki (First)\n");
    printf("3 - zdejmij liczbe ze stosu (Pop)\n");
    printf("4 - sprawdz czy stos jest pusty\n");
    printf("5 - sprawdz czy stos jest pelny\n");
    printf("6 - koniec programu\n");
    printf("\n");
}

int main() {
    int temp = 0;
    int option = 0;
    printf("KOLEJKA- First In First Out\n");
    while (1) {
        menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                if (!isQueueFull()) {
                    printf("Podaj wartosc: ");
                    scanf("%d", &temp);
                    Push(temp);
                } else {
                    printf("Opracja nieozwolona KOLEJKA pelna!!!\n\n");
                }
                break;
            case 2:
                if (!isQueueEmpty()) {
                    temp = First();
                    printf("Odczytana wartosc: %d", temp);
                } else {
                    printf("Opracja nieozwolona KOLEJKA pusta!!!\n\n");
                }
                break;
            case 3:
                if (!isQueueEmpty()){
                temp=Pop();
            printf("Odczytana wartosc: %d", temp);
            } else{
            printf("operacja niedozwolona STOS pusty!!!\n\n");
            }
            break;
            case 4:
                if (!isQueueEmpty()) {
                    printf("KOLEJKA jest pusta.\n");
                } else {
                    printf("KOLEJKA nie jest pusta.\n");
                }
                break;
            case 5:
                if (isQueueFull()) {
                    printf("KOLEJKA jest pelna.\n");
                } else {
                    printf("KOLEJKA nie jest pelna.\n");
                }
                break;
            case 6:
                return 0;
            default:
                printf("Wybierz wlasciwa opcje.\n\n");
        }
    }
    return 0;
}