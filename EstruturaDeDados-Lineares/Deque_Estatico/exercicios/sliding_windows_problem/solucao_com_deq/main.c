#include <stdio.h>
#include "deque.c"

void sliding_window_max_D(int L[], int n, int k) {
    Deque D;
    init_deque(&D);
    
    // Processa os primeiros k elementos
    int i = 0;
    for (i = 0; i < k; i++) {
        // Remove do final enquanto o elemento atual é maior
        while (!is_empty(&D) && L[get_end(&D)] <= L[i]) {
            remove_end(&D);
        }
        add_end(&D, i);
    }
    
    // Processa o restante do array
    for ( i = k; i < n; i++) {
        // Imprime o máximo da janela anterior
        printf("%d ", L[get_front(&D)]);
        
        // Remove elementos que estão fora da janela
        while (!is_empty(&D) && get_front(&D) <= i - k) {
            remove_front(&D);
        }
        
        // Remove do final enquanto o elemento atual é maior
        while (!is_empty(&D) && L[get_end(&D)] <= L[i]) {
            remove_end(&D);
        }
        
        add_end(&D, i);
    }
    
    // Imprime o máximo da última janela
    printf("%d\n", L[get_front(&D)]);
}

int main() {
    // Teste 1
    int L1[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n1 = sizeof(L1) / sizeof(L1[0]);
    int k1 = 3;
    
    printf("Teste 1: ");
    sliding_window_max_D(L1, n1, k1); // Output: 3 3 5 5 6 7
    
    // Teste 2
    int L2[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n2 = sizeof(L2) / sizeof(L2[0]);
    int k2 = 4;
    
    printf("Teste 2: ");
    sliding_window_max_D(L2, n2, k2); // Output: 10 10 10 15 15 90 90
    
    // Teste 3 - caso com todos elementos iguais
    int L3[] = {5, 5, 5, 5, 5, 5};
    int n3 = sizeof(L3) / sizeof(L3[0]);
    int k3 = 3;
    
    printf("Teste 3: ");
    sliding_window_max_D(L3, n3, k3); // Output: 5 5 5 5
    
    return 0;
}
