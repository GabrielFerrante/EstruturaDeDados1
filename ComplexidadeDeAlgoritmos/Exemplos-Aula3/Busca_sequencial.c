#include <stdio.h>

int busca_sequencial(int array[], int tamanho, int elemento) {
	int i = 0; //------------------------------------------------------1
    for (i = 0; i < tamanho; i++) {
        if (array[i] == elemento) {
            return i; // Retorna o índice se encontrar o elemento
        }
    }
    return -1; // Retorna -1 se não encontrar
}

//Analise de complexidade
//Neste caso é muito simples, é somente um loop
// Fica:
// T(n) = SOMATÓRIO- LS: n-1, LI: i=1, Termo: 1 + 1
// Logo, T(n) = N-1 + 1
//Big O(n) no pior caso.

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int elemento = 9;

    int resultado = busca_sequencial(arr, tamanho, elemento);

    if (resultado != -1) {
        printf("Elemento encontrado no indice: %d\n", resultado);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    return 0;
}
