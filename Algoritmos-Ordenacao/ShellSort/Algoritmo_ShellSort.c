#include <stdio.h>

void shellSort(int arr[], int n) {
    int gap = n / 2;
    // Inicia com um gap grande e reduz gradualmente
    for (gap = n / 2; gap > 0; gap /= 2) {
    	int i = gap;
        // Faz um insertion sort para este gap
        for (i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // Desloca elementos até encontrar a posição correta para arr[i]
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Exemplo de uso
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}
