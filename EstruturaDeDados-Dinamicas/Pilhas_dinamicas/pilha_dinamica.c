#include "pilha_dinamica.h"
#include <stdlib.h>

void inicializar(PilhaDinamica* pilha) {
    pilha->topo = NULL;
}

void empilhar(PilhaDinamica* pilha, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(PilhaDinamica* pilha) {
    if (vazia(pilha)) return -1; // Retorna -1 se pilha vazia
    
    No* temp = pilha->topo;
    int valor = temp->valor;
    pilha->topo = temp->proximo;
    free(temp);
    return valor;
}

int vazia(PilhaDinamica* pilha) {
    return pilha->topo == NULL;
}
