#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, chave, j;
    
    for (i = 1; i < n; i++) {
        chave = arr[i];  // Elemento atual a ser inserido na posi��o correta
        j = i - 1;
        
        // Move os elementos do arr[0..i-1] que s�o maiores que a chave
        // para uma posi��o � frente de sua posi��o atual
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;  // Insere a chave na posi��o correta
    }
}

// Fun��o para imprimir o array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: ");
    printArray(arr, n);
    
    insertionSort(arr, n);
    
    printf("Array ordenado: ");
    printArray(arr, n);
    
    return 0;
}
