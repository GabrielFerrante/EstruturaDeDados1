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

void test_FindMin(Priority_queue *q) {
    int min_index = FindMin(q);
    if (min_index != -1) {
        printf("FindMin retornou índice: %d, Key: %d, Prioridade: %d\n", 
               min_index, q->data[min_index].key, q->data[min_index].p);
    } else {
        printf("Fila vazia - FindMin retornou -1\n");
    }
}

int main() {
	setlocale(LC_ALL, "portuguese");
    Priority_queue pq;
    init_priority_queue(&pq);
    
    printf("=== Teste 1: Função FindMin ===\n");
    enqueue(&pq, 10, 3);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 2);
    
    printf("Estado da fila:\n");
    print_queue(&pq);
    test_FindMin(&pq);
    
    printf("\n=== Teste 2: Dequeue usando FindMin ===\n");
    printf("Antes do dequeue:\n");
    print_queue(&pq);
    
    Node removed = dequeue(&pq);
    printf("Removido - Key: %d, Prioridade: %d\n", removed.key, removed.p);
    
    printf("Após dequeue:\n");
    print_queue(&pq);
    test_FindMin(&pq);
    
    printf("\n=== Teste 3: Múltiplas operações ===\n");
    enqueue(&pq, 40, 5);
    enqueue(&pq, 50, 0); // Prioridade mais alta
    enqueue(&pq, 60, 4);
    
    printf("Estado após novas inserções:\n");
    print_queue(&pq);
    test_FindMin(&pq);
    
    printf("\nRemovendo todos os elementos em ordem de prioridade:\n");
    while (!is_empty(&pq)) {
        Node n = dequeue(&pq);
        printf("Key: %d, Prioridade: %d\n", n.key, n.p);
    }
    
    printf("\n=== Teste 4: Fila vazia ===\n");
    test_FindMin(&pq);
    
    printf("\n=== Teste 5: Peek com FindMin ===\n");
    enqueue(&pq, 100, 7);
    enqueue(&pq, 200, 2);
    
    printf("Estado da fila:\n");
    print_queue(&pq);
    
    Node top = peek(&pq);
    printf("Peek - Key: %d, Prioridade: %d\n", top.key, top.p);
    
    printf("Estado após peek (não deve mudar):\n");
    print_queue(&pq);
    
    return 0;
}
