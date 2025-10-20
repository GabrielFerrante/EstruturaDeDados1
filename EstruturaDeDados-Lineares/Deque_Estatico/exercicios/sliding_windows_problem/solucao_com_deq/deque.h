#ifndef DEQUE_H
#define DEQUE_H

#define MAX_SIZE 100000  // Tamanho máximo assumido para o deque

typedef struct {
    int array[MAX_SIZE];
    int start;
    int end;
    int size;
} Deque;

// Funções básicas do deque
void init_deque(Deque* d);
int is_empty(Deque* d);
int is_full(Deque* d);

// Operações no início
void add_front(Deque* d, int value);
int remove_front(Deque* d);
int get_front(Deque* d);

// Operações no final
void add_end(Deque* d, int value);
int remove_end(Deque* d);
int get_end(Deque* d);

#endif
