#include <stdio.h>
#include "pilha.c"
#include "conversor.h"

void decimal_para_binario(int decimal) {
    Pilha pilha;
    inicializar(&pilha);
    
    int numero = decimal;
    
    // Caso especial para 0
    if (numero == 0) {
        printf("0 em binário: 0\n");
        return;
    }
    
    // Empilha os restos das divisões por 2
    while (numero > 0) {
        int resto = numero % 2;
        if (!empilhar(&pilha, resto)) {
            printf("Erro: Pilha cheia!\n");
            return;
        }
        numero = numero / 2;
    }
    
    // Desempilha para obter a sequência correta
    printf("%d em binário: ", decimal);
    int bit;
    while (!esta_vazia(&pilha)) {
        desempilhar(&pilha, &bit);
        printf("%d", bit);
    }
    printf("\n");
}

