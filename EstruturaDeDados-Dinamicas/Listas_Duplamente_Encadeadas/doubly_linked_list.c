#include "doubly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void init(DoublyLinkedList* dl) {
    dl->head = NULL;
}

void add_head(DoublyLinkedList* dl, int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->prev = NULL;
    new_node->next = dl->head;

    if (dl->head != NULL) {
        dl->head->prev = new_node;
    }
    
    dl->head = new_node;
}

void add_tail(DoublyLinkedList* dl, int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;

    if (dl->head == NULL) {
        // Lista vazia
        new_node->prev = NULL;
        dl->head = new_node;
        return;
    }

    // Encontrar o último nó
    Node* current = dl->head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Inserir após o último nó
    current->next = new_node;
    new_node->prev = current;
}

int remove_node(DoublyLinkedList* dl, int key) {
    if (dl->head == NULL) {
        return 0; // Lista vazia
    }

    Node* current = dl->head;
    
    // Procurar o nó com a chave
    while (current != NULL && current->key != key) {
        current = current->next;
    }

    if (current == NULL) {
        return 0; // Chave não encontrada
    }

    // Ajustar os ponteiros dos nós vizinhos
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        // Removendo o primeiro nó
        dl->head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    return 1; // Remoção bem-sucedida
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
    if (dl->head == NULL) {
        printf("Lista (tras): \n");
        return;
    }

    // Encontrar o último nó
    Node* current = dl->head;
    while (current->next != NULL) {
        current = current->next;
    }

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
}
