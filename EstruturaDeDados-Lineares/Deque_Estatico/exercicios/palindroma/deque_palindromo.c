#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "deque_palindromo.h"

void inicializar_deque(Deque *dq) {
    dq->frente = 0;
    dq->tras = -1;
    dq->tamanho = 0;
}

int deque_vazio(Deque *dq) {
    return dq->tamanho == 0;
}

int deque_cheio(Deque *dq) {
    return dq->tamanho == MAX;
}

int tamanho_deque(Deque *dq) {
    return dq->tamanho;
}

int inserir_fim(Deque *dq, char elemento) {
    if (deque_cheio(dq)) {
        return 0; // Falha - deque cheio
    }
    
    dq->tras = (dq->tras + 1) % MAX;
    dq->dados[dq->tras] = elemento;
    dq->tamanho++;
    
    // Se era o primeiro elemento, ajusta frente
    if (dq->tamanho == 1) {
        dq->frente = dq->tras;
    }
    
    return 1; // Sucesso
}

int inserir_inicio(Deque *dq, char elemento) {
    if (deque_cheio(dq)) {
        return 0; // Falha - deque cheio
    }
    
    dq->frente = (dq->frente - 1 + MAX) % MAX;
    dq->dados[dq->frente] = elemento;
    dq->tamanho++;
    
    // Se era o primeiro elemento, ajusta tras
    if (dq->tamanho == 1) {
        dq->tras = dq->frente;
    }
    
    return 1; // Sucesso
}

int remover_inicio(Deque *dq, char *elemento) {
    if (deque_vazio(dq)) {
        return 0; // Falha - deque vazio
    }
    
    *elemento = dq->dados[dq->frente];
    dq->frente = (dq->frente + 1) % MAX;
    dq->tamanho--;
    
    return 1; // Sucesso
}

int remover_fim(Deque *dq, char *elemento) {
    if (deque_vazio(dq)) {
        return 0; // Falha - deque vazio
    }
    
    *elemento = dq->dados[dq->tras];
    dq->tras = (dq->tras - 1 + MAX) % MAX;
    dq->tamanho--;
    
    return 1; // Sucesso
}

int frente_deque(Deque *dq, char *elemento) {
    if (deque_vazio(dq)) {
        return 0; // Falha - deque vazio
    }
    
    *elemento = dq->dados[dq->frente];
    return 1; // Sucesso
}

int fim_deque(Deque *dq, char *elemento) {
    if (deque_vazio(dq)) {
        return 0; // Falha - deque vazio
    }
    
    *elemento = dq->dados[dq->tras];
    return 1; // Sucesso
}

// Função principal que verifica se uma palavra é palíndromo
int eh_palindromo(char *palavra) {
    Deque D;
    inicializar_deque(&D);
    
    int k = strlen(palavra);
    
    printf("=== VERIFICANDO PALINDROMO: '%s' ===\n", palavra);
    printf("Tamanho da palavra: %d\n", k);
    
    // Adiciona todos os caracteres no deque (ignorando case e espaços)
    int caracteres_validos = 0;
    int i = 0;
    for (i = 0; i < k; i++) {
        char c = palavra[i];
        
        // Ignora espaços e pontuação (opcional)
        if (isalpha(c)) {
            // Converte para minúscula para comparação case-insensitive
            c = tolower(c);
            if (inserir_fim(&D, c)) {
                caracteres_validos++;
                printf("Adicionado '%c' no final do deque\n", c);
            }
        }
    }
    
    printf("Deque apos adicionar todos os caracteres: ");
    if (!deque_vazio(&D)) {
        int temp_frente = D.frente;
        int i = 0;
        for ( i = 0; i < D.tamanho; i++) {
            printf("%c ", D.dados[temp_frente]);
            temp_frente = (temp_frente + 1) % MAX;
        }
        printf("\n");
    }
    
    printf("Iniciando verificacao de palindromo...\n");
    
    // Compara os caracteres do início e do fim
    while (tamanho_deque(&D) > 1) {
        char esquerda, direita;
        
        remover_inicio(&D, &esquerda);
        remover_fim(&D, &direita);
        
        printf("Comparando: '%c' (inicio) com '%c' (fim) -> ", esquerda, direita);
        
        if (esquerda != direita) {
            printf("DIFERENTES - NAO E PALINDROMO! \n");
            return 0; // Não é palíndromo
        } else {
            printf("IGUAIS \n");
        }
    }
    
    printf("Todos os caracteres coincidem! E PALINDROMO! ?\n");
    return 1; // É palíndromo
}

// Versão alternativa que mostra o estado do deque a cada passo
int eh_palindromo_detalhado(char *palavra) {
    Deque D;
    inicializar_deque(&D);
    
    int k = strlen(palavra);
    
    printf("\n=== VERIFICACAO DETALHADA: '%s' ===\n", palavra);
    
    // Adiciona todos os caracteres válidos no deque
    int i = 0;
    for (i = 0; i < k; i++) {
        char c = palavra[i];
        if (isalpha(c)) {
            inserir_fim(&D, tolower(c));
        }
    }
    
    printf("Estado inicial do deque: ");
    int temp_frente = D.frente;
    i = 0;
    for (i = 0; i < D.tamanho; i++) {
        printf("%c ", D.dados[temp_frente]);
        temp_frente = (temp_frente + 1) % MAX;
    }
    printf("\n");
    
    int passo = 1;
    while (tamanho_deque(&D) > 1) {
        printf("\n--- Passo %d ---\n", passo);
        
        char esquerda, direita;
        remover_inicio(&D, &esquerda);
        remover_fim(&D, &direita);
        
        printf("Removido do inicio: '%c'\n", esquerda);
        printf("Removido do fim: '%c'\n", direita);
        
        printf("Comparacao: '%c' vs '%c' -> ", esquerda, direita);
        
        if (esquerda != direita) {
            printf("DIFERENTES\n");
            printf("RESULTADO: NAO E PALINDROMO \n");
            return 0;
        } else {
            printf("IGUAIS \n");
        }
        
        // Mostra estado atual do deque
        if (tamanho_deque(&D) > 0) {
            printf("Deque restante: ");
            temp_frente = D.frente;
            int i = 0;
            for (i = 0; i < D.tamanho; i++) {
                printf("%c ", D.dados[temp_frente]);
                temp_frente = (temp_frente + 1) % MAX;
            }
            printf("\n");
        }
        
        passo++;
    }
    
    printf("\nRESULTADO: E PALINDROMO\n");
    return 1;
}
