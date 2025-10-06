#include <stdio.h>
#include "fila_estatica.h"

void inicializar(Fila *f) {
    f->frente = 0;
    f->tras = 0;
    f->tamanho = 0;
}

int enqueue(Fila *f, int elemento) {
    if (esta_cheia(f)) {
        return 0; // Falha - fila cheia
    }
    
    f->dados[f->tras] = elemento;
    f->tras = (f->tras + 1) % MAX;
    f->tamanho++;
    return 1; // Sucesso
}

int dequeue(Fila *f, int *elemento) {
    if (esta_vazia(f)) {
        return 0; // Falha - fila vazia
    }
    
    *elemento = f->dados[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return 1; // Sucesso
}

int frente(Fila *f, int *elemento) {
    if (esta_vazia(f)) {
        return 0; // Falha - fila vazia
    }
    
    *elemento = f->dados[f->frente];
    return 1; // Sucesso
}

int esta_vazia(Fila *f) {
    return f->tamanho == 0;
}

int esta_cheia(Fila *f) {
    return f->tamanho == MAX;
}

int tamanho(Fila *f) {
    return f->tamanho;
}

void imprimir_fila(Fila *f) {
    if (esta_vazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    
    printf("Fila (frente -> tras): ");
    int i = f->frente;
    int count = 0;
    for (count = 0; count < f->tamanho; count++) {
        printf("%d ", f->dados[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}
