int findMin(int *ptrn, int size) {
    int min = ptrn[0];
    for (int i = 0; i < size; i++) {
        if (min > ptrn[i]) {
            min = ptrn[i];
        }
    }
    return min;
}

int findMax(int *ptrn, int size) {
    int max = ptrn[0];
    for (int i = 0; i < size; i++) {
        if (max < ptrn[i]) {
            max = ptrn[i];
        }
    }
    return max;
}

//float findAvg(int *ptrn, int sum, int size) {
//    for (int i = 0; i < size; i++) {
//        sum += ptrn[i];
//    }
//    float average = (float) sum / size;
//    return average;
//}
float findAvg(int *array, int size) {
    int sum=0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    float average = (float) sum / size;
    return average;
}
