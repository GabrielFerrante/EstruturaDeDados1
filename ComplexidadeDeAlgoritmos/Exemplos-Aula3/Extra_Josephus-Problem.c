#include <stdio.h>
#include <stdlib.h>

int elimina_pessoas(int* pessoas, int tamanho, int n, int k, int index) {
    if (n == 1) {
        // Encontra e retorna o último sobrevivente
        int i = 0;
        for (i = 0; i < tamanho; i++) {
            if (pessoas[i] != -1) {
                return i;
            }
        }
    }

    // Conta k pessoas a partir do índice atual
    int passos = 1;
    int next_index = index;
    while (passos < k) {
        next_index = (next_index + 1) % tamanho;
        if (pessoas[next_index] != -1) {
            passos++;
        }
    }

    // Elimina a pessoa encontrada
    pessoas[next_index] = -1;
    printf("\nELIMINADA: Pessoa %d\n", next_index);

    // Encontra a próxima pessoa viva para iniciar a próxima contagem
    int novo_index = next_index;
    do {
        novo_index = (novo_index + 1) % tamanho;
    } while (pessoas[novo_index] == -1);

    // Mostra o estado atual das pessoas
    printf("Estado atual:\n");
    int i = 0;
    for (i = 0; i < tamanho; i++) {
        if (pessoas[i] == -1) {
            printf("Pessoa %d: Eliminada\n", i);
        } else {
            printf("Pessoa %d: Sobrevivente\n", i);
        }
    }

    return elimina_pessoas(pessoas, tamanho, n - 1, k, novo_index);
}

int main() {
    int n = 14;
    int k = 2;
    if (n == k) {
        printf("NAO PERMITIDO !");
        return 0;
    }

    int* pessoas = (int*)malloc(n * sizeof(int));
    int i = 0;
    for (i = 0; i < n; i++) {
        pessoas[i] = 1;
    }

    printf("Estado inicial:\n");
    i = 0;
    for (i = 0; i < n; i++) {
        printf("Pessoa %d: Sobrevivente\n", i);
    }

    int resultado = elimina_pessoas(pessoas, n, n, k, 0);
    printf("\nA pessoa sobrevivente seria: %d\n", resultado);

    free(pessoas);
    return 0;
}
