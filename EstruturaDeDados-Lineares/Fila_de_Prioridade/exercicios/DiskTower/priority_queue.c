#include "priority_queue.h"
#include <stdio.h>

void init_priority_queue(Priority_queue *q) {
    q->tail = 0;
    q->size = 0;
}

int is_empty(Priority_queue *q) {
    return q->size == 0;
}

int is_full(Priority_queue *q) {
    return q->size == MAX_SIZE;
}

int FindMax(Priority_queue *q) {
    if (is_empty(q)) {
        return -1;
    }
    
    int index = 0;
    int max = q->data[index];
    int i = 1;
    for (i = 1; i < q->tail; i++) {
        if (q->data[i] > max) {
            max = q->data[i];
            index = i;
        }
    }
    return index;
}

void enqueue(Priority_queue *q, int value) {
    if (is_full(q)) {
        printf("Fila de prioridade cheia!\n");
        return;
    }
    
    q->data[q->tail] = value;
    q->tail++;
    q->size++;
}

int dequeue(Priority_queue *q) {
    if (is_empty(q)) {
        printf("Fila de prioridade vazia!\n");
        return -1;
    }
    
    int max_index = FindMax(q);
    int result = q->data[max_index];
    
    // Remove o elemento deslocando os elementos posteriores
    int i;
    for ( i = max_index; i < q->tail - 1; i++) {
        q->data[i] = q->data[i + 1];
    }
    
    q->tail--;
    q->size--;
    
    return result;
}

int peek(Priority_queue *q) {
    if (is_empty(q)) {
        return -1;
    }
    
    int max_index = FindMax(q);
    return q->data[max_index];
}
