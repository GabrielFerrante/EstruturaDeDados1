#include <stdio.h>
#include "pilha.h"

void inicializar(Pilha *p) {
    p->topo = -1;
}

int empilhar(Pilha *p, int elemento) {
    if (esta_cheia(p)) {
        return 0; // Falha
    }
    p->dados[++p->topo] = elemento;
    return 1; // Sucesso
}

int desempilhar(Pilha *p, int *elemento) {
    if (esta_vazia(p)) {
        return 0; // Falha
    }
    *elemento = p->dados[p->topo--];
    return 1; // Sucesso
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

int esta_cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void imprimir_pilha(Pilha *p) {
    if (esta_vazia(p)) {
        printf("Pilha vazia\n");
        return;
    }
    int i = 0;
    printf("Pilha (topo -> base): ");
    for (i = p->topo; i >= 0; i--) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}
