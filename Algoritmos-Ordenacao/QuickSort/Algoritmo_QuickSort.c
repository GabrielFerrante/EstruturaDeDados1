#include <stdio.h>
#include <stdlib.h>

// Fun��o para trocar dois elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o para particionar o array usando o �ltimo elemento como piv�
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Seleciona o �ltimo elemento como piv�
    int i = (low - 1);
	int j = low;     // �ndice do menor elemento

    for (j = low; j <= high - 1; j++) {
        // Se o elemento atual � menor ou igual ao piv�
        if (arr[j] <= pivot) {
            i++; // Incrementa o �ndice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fun��o principal do QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi � o �ndice de particionamento
        int pi = partition(arr, low, high);

        // Ordena os elementos separadamente antes e depois da parti��o
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fun��o para imprimir o array
void printArray(int arr[], int size) {
	int i = 0;
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Programa principal para testar a implementa��o
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: \n");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("Array ordenado: \n");
    printArray(arr, n);
    
    return 0;
}
