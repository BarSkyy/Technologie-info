#include <iostream>
#include <algorithm>

#define SIZE 10
using namespace std;

//int findMiddle(int *ptrn, int middle) {
//    int copy[SIZE];
//    for (int i; i < SIZE; i++)
//        copy[i] = ptrn[i];
//    sort(ptrn, ptrn + SIZE);
//    if (SIZE % 2 == 0) {
//        middle = (ptrn[SIZE / 2 - 1] + ptrn[SIZE / 2]) / 2.0;
//    } else {
//        middle = ptrn[SIZE / 2];
//    }
//}
int findMax(int *ptrn) {
    int max = ptrn[0];
    for (int i = 0; i < SIZE; i++) {
        if (max < ptrn[i]) {
            max = ptrn[i];
        }
    }
    return max;
}

int findMin(int *ptrn) {
    int min = ptrn[0];
    for (int i = 0; i < SIZE; i++) {
        if (min > ptrn[i]) {
            min = ptrn[i];
        }
    }
    return min;
}

int findAvg(int *ptrn, int sum) {
    for (int i = 0; i < SIZE; i++) {
        sum += ptrn[i];
    }
    float average = (float) sum / SIZE;
    return average;
}

int main() {
    printf("Arrays\n");
    int numbers[SIZE] = {4, 6, -8, 37, 20, 12, 49, 67, 42, 23};
    for (int i = 0; i < SIZE; i++) {
        printf("numbers[%d]=%d\n", i, numbers[i]);
    }
//    int max = numbers[0];
//    for (int i = 0; i < SIZE; i++) {
//        if (max < numbers[i]) {
//            max = numbers[i];
//        }
//    }
//    printf("max=%d\n", max);
//    int min = numbers[0];
//    for (int i = 0; i < SIZE; i++) {
//        if (min > numbers[i]) {
//            min = numbers[i];
//        }
//    }
    int Max = 0;
    Max = findMax(numbers);
    printf("max=%d\n", Max);
    int Min = 0;
    Min = findMin(numbers);
    printf("min=%d\n", Min);
    float Avg = 0;
    Avg = findAvg(numbers, SIZE);
    printf("Avg=%.2f", Avg);
//    for (int i = 0; i < SIZE; i++) {
//        sum += numbers[i];
//    }
//    float average = (float) sum / SIZE;
//    printf("average=%.2f\n", average);
    double middle;
    //middle= findMiddle(numbers, middle);
    //printf("middle=%.2f", middle);
//    sort(numbers, numbers + SIZE);
//    if (SIZE % 2 == 0) {
//        middle = (numbers[SIZE / 2 - 1] + numbers[SIZE / 2]) / 2.0;
//    } else {
//        middle = numbers[SIZE / 2];
//    }
//    printf("middle=%.2f", middle);
    return 0;
}
/*  while (1) {
      printf("Wprowadz pierwsza liczbe:");
      int numer1=0;
      scanf("%d",&numer1);
      if (numer1==0) {
          break;
      }
      printf("Wprowadz druga liczbe:");
      int numer2=0;
      scanf("%d",&numer2);
      if (numer2==0) {
          break;
      }
  }
  char znak;
  printf("Wprowadz operator:" );
  scanf("%c",&znak);
  if(znak=='+')
  printf("%d+%d=%d\n",numer1,numer2,numer1+numer2);
  if(znak=='-')
      printf("%d-%d=%d\n",numer1,numer2,numer1-numer2);
  if(znak=='*')
      printf("%d*%d=%d\n",numer1,numer2,numer1*numer2);
  if(znak=='/')
      printf("%d/%d=%d\n",numer1,numer2,numer1/numer2);

  return 0;
}*/