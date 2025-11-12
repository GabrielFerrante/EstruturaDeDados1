#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Node {
    int key;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} DoublyLinkedList;

void init(DoublyLinkedList* dl);
void add_head(DoublyLinkedList* dl, int key);
void add_tail(DoublyLinkedList* dl, int key);
int remove_node(DoublyLinkedList* dl, int key);
void display_forward(DoublyLinkedList* dl);
void display_backward(DoublyLinkedList* dl);
void free_list(DoublyLinkedList* dl);

#endif
