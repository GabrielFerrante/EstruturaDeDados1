#ifndef DEQUE_H
#define DEQUE_H

#define MAX_SIZE 100000  // Tamanho m�ximo assumido para o deque

typedef struct {
    int array[MAX_SIZE];
    int start;
    int end;
    int size;
} Deque;

// Fun��es b�sicas do deque
void init_deque(Deque* d);
int is_empty(Deque* d);
int is_full(Deque* d);

// Opera��es no in�cio
void add_front(Deque* d, int value);
int remove_front(Deque* d);
int get_front(Deque* d);

// Opera��es no final
void add_end(Deque* d, int value);
int remove_end(Deque* d);
int get_end(Deque* d);

#endif
