#include <stdio.h>

int busca_binaria_iterativa(int array[], int tamanho, int elemento) {
    int inicio = 0;
    int fim = tamanho - 1;
    
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2; // Evita overflow
        
        if (array[meio] == elemento) {
            return meio; // Elemento encontrado
        } else if (array[meio] < elemento) {
            inicio = meio + 1; // Busca na metade direita
        } else {
            fim = meio - 1; // Busca na metade esquerda
        }
    }
    
    return -1; // Elemento não encontrado
}

int main() {
    int arr[] = {1, 2, 5, 5, 6, 9}; // Array ordenado
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int elemento;
    
    printf("Array: ");
    int i = 0;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Teste 1: Elemento presente
    elemento = 6;
    int resultado = busca_binaria_iterativa(arr, tamanho, elemento);
    if (resultado != -1) {
        printf("Elemento %d encontrado no indice %d.\n", elemento, resultado);
    } else {
        printf("Elemento %d nao encontrado.\n", elemento);
    }
    
    // Teste 2: Elemento não presente
    elemento = 7;
    resultado = busca_binaria_iterativa(arr, tamanho, elemento);
    if (resultado != -1) {
        printf("Elemento %d encontrado no indice %d.\n", elemento, resultado);
    } else {
        printf("Elemento %d nao encontrado.\n", elemento);
    }
    
    return 0;
}
