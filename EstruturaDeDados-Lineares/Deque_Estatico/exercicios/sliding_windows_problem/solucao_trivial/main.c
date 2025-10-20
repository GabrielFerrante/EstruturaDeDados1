#include <stdio.h>
#include <stdlib.h>

// Versão simples (O(n*k))
// O problema é quando K cresce
// K = p(n) = n/2
//Sendo O(n.n/2) = O(n²)
void sliding_window_max(int L[], int n, int k) {
	int i = 0;
    for (i = 0; i <= n - k; i++) {
        int max = L[i];
        int j = 1;
        for ( j = 1; j < k; j++) {
            if (L[i + j] > max) {
                max = L[i + j];
            }
        }
        printf("%d ", max);
    }
    printf("\n");
}
int main() {
    int L[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(L) / sizeof(L[0]);
    int k = 3;

    printf("Versao trivial: ");
    sliding_window_max(L, n, k);


    return 0;
}
