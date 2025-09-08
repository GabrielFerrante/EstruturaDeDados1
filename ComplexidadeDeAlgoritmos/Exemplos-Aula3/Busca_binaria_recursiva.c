#include <stdio.h>

int busca_binaria_recursiva(int arr[], int inicio, int fim, int alvo) {
    if (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        if (arr[meio] == alvo)
            return meio;
        else if (arr[meio] > alvo)
            return busca_binaria_recursiva(arr, inicio, meio - 1, alvo);
        else
            return busca_binaria_recursiva(arr, meio + 1, fim, alvo);
    }
    return -1;
}
//Analise da complexidade
//Toda vez que é executada a função, temos o problema sendo divido na metade.
//Podemos escrever a T(n), assim:
//T(n) = T(n/2) + O(1)
//T(n) = T(n/4) + 1 + 1
//T(n) = T(n/8) + 1 + 1 + 1
//A última T(n) pode ser transformada como:
//T(n) = T(n/8) + 3.1
//Para um K arbitrário:
//T(n) = T(n/2^k) + k.1
//Condição de parada: n/2^k = 1, logo, n = 2^k, k = log2N
//T(n) = T(1) + log2n . 1
//Big O(log2n), no pior caso.

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    int alvo = 16;
    
    int resultado = busca_binaria_recursiva(arr, 0, n - 1, alvo);
    
    if (resultado != -1)
        printf("Elemento encontrado no indice %d\n", resultado);
    else
        printf("Elemento nao encontrado\n");
    
    return 0;
}
