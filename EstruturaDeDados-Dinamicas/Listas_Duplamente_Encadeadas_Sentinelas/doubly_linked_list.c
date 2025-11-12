#include "doubly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void init(DoublyLinkedList* dl) {
    dl->head = NULL;
    dl->tail = NULL;
}

void add_head(DoublyLinkedList* dl, int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->prev = NULL;
    new_node->next = dl->head;

    if (dl->head != NULL) {
        dl->head->prev = new_node;
    } else {
        // Lista vazia, tail também aponta para o novo nó
        dl->tail = new_node;
    }
    
    dl->head = new_node;
}

void add_tail(DoublyLinkedList* dl, int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;
    new_node->prev = dl->tail;

    if (dl->tail != NULL) {
        dl->tail->next = new_node;
    } else {
        // Lista vazia, head também aponta para o novo nó
        dl->head = new_node;
    }
    
    dl->tail = new_node;
}

int remove_node(DoublyLinkedList* dl, int key) {
    Node* current = dl->head;
    
    while (current != NULL) {
        if (current->key == key) {
            // Ajusta os ponteiros dos nós vizinhos
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                // Removendo o primeiro nó
                dl->head = current->next;
            }
            
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                // Removendo o último nó
                dl->tail = current->prev;
            }
            
            free(current);
            return 1; // Remoção bem-sucedida
        }
        current = current->next;
    }
    
    return 0; // Chave não encontrada
}

void display_forward(DoublyLinkedList* dl) {
    Node* current = dl->head;
    printf("Lista (frente): ");
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
}

void display_backward(DoublyLinkedList* dl) {
    Node* current = dl->tail;
    printf("Lista (tras): ");
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->prev;
    }
    printf("\n");
}

void free_list(DoublyLinkedList* dl) {
    Node* current = dl->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    dl->head = NULL;
    dl->tail = NULL;
}
