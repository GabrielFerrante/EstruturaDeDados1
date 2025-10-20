#include <stdio.h>
#include "priority_queue.c"
#include <locale.h>

void print_queue(Priority_queue *q) {
    printf("Conteúdo da fila: ");
    int i = 0;
    for (i = 0; i < q->size; i++) {
        printf("(k:%d,p:%d) ", q->data[i].key, q->data[i].p);
    }
    printf("\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    Priority_queue pq;
    init_priority_queue(&pq);
    
    printf("=== Teste 1: Inserção e remoção básica ===\n");
    enqueue(&pq, 10, 3);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 2);
    enqueue(&pq, 40, 5);
    enqueue(&pq, 50, 4);
    
    printf("Estado após inserções:\n");
    print_queue(&pq);
    
    printf("\nElementos em ordem de prioridade:\n");
    while (!is_empty(&pq)) {
        Node n = dequeue(&pq);
        printf("Key: %d, Prioridade: %d\n", n.key, n.p);
    }
    
    printf("\n=== Teste 2: Verificação do peek ===\n");
    enqueue(&pq, 100, 5);
    enqueue(&pq, 200, 2);
    enqueue(&pq, 300, 8);
    
    printf("Estado após inserções:\n");
    print_queue(&pq);
    
    Node top = peek(&pq);
    printf("Topo - Key: %d, Prioridade: %d\n", top.key, top.p);
    
    // Remove um elemento e verifica o próximo
    dequeue(&pq);
    printf("Estado após dequeue:\n");
    print_queue(&pq);
    
    top = peek(&pq);
    printf("Novo topo - Key: %d, Prioridade: %d\n", top.key, top.p);
    
    printf("\n=== Teste 3: Caso com prioridades iguais ===\n");
    Priority_queue pq2;
    init_priority_queue(&pq2);
    
    enqueue(&pq2, 1, 2);
    enqueue(&pq2, 2, 2);
    enqueue(&pq2, 3, 2);
    
    printf("Estado com prioridades iguais:\n");
    print_queue(&pq2);
    
    printf("Remoção em ordem:\n");
    while (!is_empty(&pq2)) {
        Node n = dequeue(&pq2);
        printf("Key: %d, Prioridade: %d\n", n.key, n.p);
    }
    
    return 0;
}
