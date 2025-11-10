#include "fila_dinamica.h"
#include <stdlib.h>

void inicializar(FilaDinamica* fila) {
    fila->frente = NULL;
    fila->tras = NULL;
}

void enfileirar(FilaDinamica* fila, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (vazia(fila)) {
        fila->frente = novo;
        fila->tras = novo;
    } else {
        fila->tras->proximo = novo;
        fila->tras = novo;
    }
}

int desenfileirar(FilaDinamica* fila) {
    if (vazia(fila)) return -1; // Retorna -1 se fila vazia
    
    No* temp = fila->frente;
    int valor = temp->valor;
    
    fila->frente = temp->proximo;
    if (fila->frente == NULL) {
        fila->tras = NULL; // Fila ficou vazia
    }
    
    free(temp);
    return valor;
}

int vazia(FilaDinamica* fila) {
    return fila->frente == NULL;
}
