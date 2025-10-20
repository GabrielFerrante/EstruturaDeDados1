#include "deque.h"
#include <stdio.h>

void init_deque(Deque* d) {
    d->start = 0;
    d->end = 0;
    d->size = 0;
}

int is_empty(Deque* d) {
    return d->size == 0;
}

int is_full(Deque* d) {
    return d->size == MAX_SIZE;
}

void add_front(Deque* d, int value) {
    if (is_full(d)) {
        printf("Deque cheio!\n");
        return;
    }
    
    d->start = (d->start - 1 + MAX_SIZE) % MAX_SIZE;
    d->array[d->start] = value;
    d->size++;
}

void add_end(Deque* d, int value) {
    if (is_full(d)) {
        printf("Deque cheio!\n");
        return;
    }
    
    d->array[d->end] = value;
    d->end = (d->end + 1) % MAX_SIZE;
    d->size++;
}

int remove_front(Deque* d) {
    if (is_empty(d)) {
        printf("Deque vazio!\n");
        return -1;
    }
    
    int value = d->array[d->start];
    d->start = (d->start + 1) % MAX_SIZE;
    d->size--;
    return value;
}

int remove_end(Deque* d) {
    if (is_empty(d)) {
        printf("Deque vazio!\n");
        return -1;
    }
    
    d->end = (d->end - 1 + MAX_SIZE) % MAX_SIZE;
    int value = d->array[d->end];
    d->size--;
    return value;
}

int get_front(Deque* d) {
    if (is_empty(d)) {
        printf("Deque vazio!\n");
        return -1;
    }
    return d->array[d->start];
}

int get_end(Deque* d) {
    if (is_empty(d)) {
        printf("Deque vazio!\n");
        return -1;
    }
    return d->array[(d->end - 1 + MAX_SIZE) % MAX_SIZE];
}
