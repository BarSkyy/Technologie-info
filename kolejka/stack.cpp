//
// Created by Student on 13.05.2026.
//
#define QUEUE_SIZE 5
int queue_table[QUEUE_SIZE] = {0};
int queue_index = 0;
int queue_index_view = 0;

int isQueueEmpty(void) {
    return (queue_index == 0) ? 1 : 0;
}

int isQueueFull(void) {
    return (queue_index == (QUEUE_SIZE)) ? 1 : 0;
}

int Pop(void) {
    if (!isQueueEmpty()) {
        queue_index--;
        return queue_table[queue_index];
    }
    return queue_table[0];
}

int First(void) {
    if (!isQueueEmpty()) {
        ++queue_index_view;
        queue_index_view % 5;
        return queue_table[queue_index+1];
    }
    return queue_table[0];
}

void Push(int val) {
    if (!isQueueFull()) {
        queue_table[queue_index] = val;
        queue_index++;
    }
}