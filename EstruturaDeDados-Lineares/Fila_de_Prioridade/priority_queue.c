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

void enqueue(Priority_queue *q, int key, int priority) {
    if (is_full(q)) {
        printf("Fila de prioridade cheia!\n");
        return;
    }
    
    // Adiciona no final
    int index = q->tail;
    q->data[index].key = key;
    q->data[index].p = priority;
    q->tail++;
    q->size++;
    
    // Ajusta o heap subindo (equivalente ao heapify_up)
    while (index > 0) {
        int parent_index = (index - 1) / 2;
        
        // Se o pai tem prioridade menor (valor maior), troca
        if (q->data[parent_index].p > q->data[index].p) {
            // Troca com o pai
            Node temp = q->data[parent_index];
            q->data[parent_index] = q->data[index];
            q->data[index] = temp;
            
            index = parent_index;
        } else {
            break;
        }
    }
}

Node dequeue(Priority_queue *q) {
    Node empty_node = {-1, -1};
    
    if (is_empty(q)) {
        printf("Fila de prioridade vazia!\n");
        return empty_node;
    }
    
    // A raiz é o elemento de maior prioridade
    Node result = q->data[0];
    
    // Move o último elemento para a raiz
    q->tail--;
    q->size--;
    q->data[0] = q->data[q->tail];
    
    // Ajusta o heap descendo (equivalente ao heapify_down)
    int index = 0;
    int size = q->size;
    
    while (1) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int smallest = index;
        
        // Encontra o filho com menor prioridade (menor valor p)
        if (left_child < size && q->data[left_child].p < q->data[smallest].p) {
            smallest = left_child;
        }
        
        if (right_child < size && q->data[right_child].p < q->data[smallest].p) {
            smallest = right_child;
        }
        
        // Se encontrou um filho com prioridade maior, troca
        if (smallest != index) {
            Node temp = q->data[index];
            q->data[index] = q->data[smallest];
            q->data[smallest] = temp;
            
            index = smallest;
        } else {
            break;
        }
    }
    
    return result;
}

Node peek(Priority_queue *q) {
    Node empty_node = {-1, -1};
    
    if (is_empty(q)) {
        printf("Fila de prioridade vazia!\n");
        return empty_node;
    }
    
    return q->data[0];
}
