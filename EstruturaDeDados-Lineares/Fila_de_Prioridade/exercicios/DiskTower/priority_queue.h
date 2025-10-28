#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define MAX_SIZE 100000

typedef struct {
    int data[MAX_SIZE];
    int tail;
    int size;
} Priority_queue;

// Fun��es b�sicas
void init_priority_queue(Priority_queue *q);
int is_empty(Priority_queue *q);
int is_full(Priority_queue *q);

// Opera��es principais
void enqueue(Priority_queue *q, int value);
int dequeue(Priority_queue *q);
int peek(Priority_queue *q);

// Fun��es auxiliares
int FindMax(Priority_queue *q);

#endif
