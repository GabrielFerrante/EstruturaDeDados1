#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define MAX_SIZE 100000

typedef struct {
    int key;
    int p;  // prioridade (quanto menor o valor, maior a prioridade)
} Node;

typedef struct {
    Node data[MAX_SIZE];
    int tail;
    int size;
} Priority_queue;

// Funções básicas
void init_priority_queue(Priority_queue *q);
int is_empty(Priority_queue *q);
int is_full(Priority_queue *q);

// Operações principais
void enqueue(Priority_queue *q, int key, int priority);
Node dequeue(Priority_queue *q);
Node peek(Priority_queue *q);

#endif
