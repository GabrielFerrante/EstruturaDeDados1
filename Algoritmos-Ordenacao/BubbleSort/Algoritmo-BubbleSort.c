#include <stdio.h>

void bubbleSort(int array[], int tamanho) {
    int i, j, temp;
    // Loop externo: controla o numero de passagens pelo array
    for (i = 0; i < tamanho - 1; i++) {
        // Loop interno: compara elementos adjacentes
        for (j = 0; j < tamanho - i - 1; j++) {
            // Se o elemento atual for maior que o proximo, troca-os
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void imprimirArray(int array[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: ");
    imprimirArray(arr, tamanho);
    
    bubbleSort(arr, tamanho);
    
    printf("Array ordenado: ");
    imprimirArray(arr, tamanho);
    
    return 0;
}
