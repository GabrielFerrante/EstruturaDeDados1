#include <stdio.h>
#include "pilha.c"
#include "verificador.h"

int eh_parentese_abertura(char c) {
    return c == '(' || c == '[' || c == '{';
}

int eh_parentese_fechamento(char c) {
    return c == ')' || c == ']' || c == '}';
}

char correspondente_abertura(char fechamento) {
    switch (fechamento) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: return '\0';
    }
}

int verificar_expressao(char *expressao) {
    Pilha pilha;
    inicializar(&pilha);
    int i = 0;
    for (i = 0; expressao[i] != '\0'; i++) {
        char caractere = expressao[i];
        
        if (eh_parentese_abertura(caractere)) {
            // Empilha parênteses de abertura
            if (!empilhar(&pilha, caractere)) {
                printf("Erro: Pilha cheia!\n");
                return 0;
            }
        }
        else if (eh_parentese_fechamento(caractere)) {
            char topo_pilha;
            
            if (esta_vazia(&pilha)) {
                // Fechamento sem abertura correspondente
                return 0;
            }
            
            // Verifica se o fechamento corresponde ao último abertura
            desempilhar(&pilha, &topo_pilha);
            if (topo_pilha != correspondente_abertura(caractere)) {
                return 0;
            }
        }
        // Ignora outros caracteres (números, operadores, etc.)
    }
    
    // A expressão é válida se a pilha estiver vazia no final
    return esta_vazia(&pilha);
}
