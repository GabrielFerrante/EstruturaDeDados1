#include <stdio.h>
#include "deque_estatico.h"

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

int inserir_frente(Deque *dq, int elemento) {
    if (deque_cheio(dq)) {
        return 0; // Falha - deque cheio
    }
    
    // Move o índice da frente para trás (circularmente)
    dq->frente = (dq->frente - 1 + MAX) % MAX;
    dq->dados[dq->frente] = elemento;
    dq->tamanho++;
    
    // Se era o primeiro elemento, ajusta tras
    if (dq->tamanho == 1) {
        dq->tras = dq->frente;
    }
    
    return 1; // Sucesso
}

int inserir_tras(Deque *dq, int elemento) {
    if (deque_cheio(dq)) {
        return 0; // Falha - deque cheio
    }
    
    // Move o índice de trás para frente (circularmente)
    dq->tras = (dq->tras + 1) % MAX;
    dq->dados[dq->tras] = elemento;
    dq->tamanho++;
    
    // Se era o primeiro elemento, ajusta frente
    if (dq->tamanho == 1) {
        dq->frente = dq->tras;
    }
    
    return 1; // Sucesso
}

int remover_frente(Deque *dq, int *elemento) {
    if (deque_vazio(dq)) {
        return 0; // Falha - deque vazio
    }
    
    *elemento = dq->dados[dq->frente];
    dq->frente = (dq->frente + 1) % MAX;
    dq->tamanho--;
    
    return 1; // Sucesso
}

int remover_tras(Deque *dq, int *elemento) {
    if (deque_vazio(dq)) {
        return 0; // Falha - deque vazio
    }
    
    *elemento = dq->dados[dq->tras];
    dq->tras = (dq->tras - 1 + MAX) % MAX;
    dq->tamanho--;
    
    return 1; // Sucesso
}

int frente_deque(Deque *dq, int *elemento) {
    if (deque_vazio(dq)) {
        return 0; // Falha - deque vazio
    }
    
    *elemento = dq->dados[dq->frente];
    return 1; // Sucesso
}

int tras_deque(Deque *dq, int *elemento) {
    if (deque_vazio(dq)) {
        return 0; // Falha - deque vazio
    }
    
    *elemento = dq->dados[dq->tras];
    return 1; // Sucesso
}

void imprimir_deque(Deque *dq) {
    if (deque_vazio(dq)) {
        printf("Deque vazio\n");
        return;
    }
    
    printf("Deque (frente -> tras): ");
    int i = dq->frente;
    int count = 0;
    for (count = 0; count < dq->tamanho; count++) {
        printf("%d ", dq->dados[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void imprimir_deque_detalhado(Deque *dq) {
    printf("=== ESTADO DO DEQUE ===\n");
    printf("Frente: %d, Tras: %d, Tamanho: %d\n", 
           dq->frente, dq->tras, dq->tamanho);
    
    if (deque_vazio(dq)) {
        printf("Deque vazio\n");
    } else {
    	int count = 0;
        printf("Elementos: ");
        int i = dq->frente;
        for (count = 0; count < dq->tamanho; count++) {
            printf("[%d]=%d ", i, dq->dados[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
    printf("=======================\n");
}
