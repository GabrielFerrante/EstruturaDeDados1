#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_index, temp;
    
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        
        // Encontra o menor elemento no subarray não ordenado
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: ");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Array ordenado: ");
    printArray(arr, n);
    
    return 0;
}
