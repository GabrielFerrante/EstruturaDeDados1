#include <stdio.h>
#include "priority_queue.c"
#include <locale.h>

void DiskTower(int L[], int n) {
    int max = n;
    Priority_queue PQ;
    init_priority_queue(&PQ);
    int i;
    for (i = 0; i < n; i++) {
        enqueue(&PQ, L[i]);
        
        // Enquanto o maior elemento na fila for igual ao max esperado
        while (peek(&PQ) == max) {
            int disk = dequeue(&PQ);
            printf("%d ", disk);
            max--;
        }
        
        printf("X\n");
    }
}

int main() {
	setlocale(LC_ALL, "portuguese");
    int n;
    
    printf("=== Problema Disk Tower ===\n");
    
    // Teste com o exemplo fornecido
    int L1[] = {4, 5, 1, 2, 3};
    n = 5;
    
    printf("\nEntrada: n = %d, discos = [4, 5, 1, 2, 3]\n", n);
    printf("Saída esperada:\n");
    printf("X\n5 4 X\nX\nX\n3 2 1\n");
    
    printf("\nSaída do programa:\n");
    DiskTower(L1, n);
    
    // Teste adicional
    printf("\n=== Teste Adicional ===\n");
    int L2[] = {3, 1, 4, 2};
    n = 4;
    
    printf("\nEntrada: n = %d, discos = [3, 1, 4, 2]\n", n);
    printf("Saída do programa:\n");
    DiskTower(L2, n);
    
    return 0;
}
