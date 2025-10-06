#include <stdio.h>
#include "pilha_estatica.h"

void inicializar_pilha(Pilha *p) {
    p->topo = -1;
}

int empilhar(Pilha *p, int elemento) {
    if (pilha_cheia(p)) {
        return 0; // Falha - pilha cheia
    }
    p->dados[++p->topo] = elemento;
    return 1; // Sucesso
}

int desempilhar(Pilha *p, int *elemento) {
    if (pilha_vazia(p)) {
        return 0; // Falha - pilha vazia
    }
    *elemento = p->dados[p->topo--];
    return 1; // Sucesso
}

int topo_pilha(Pilha *p, int *elemento) {
    if (pilha_vazia(p)) {
        return 0; // Falha - pilha vazia
    }
    *elemento = p->dados[p->topo];
    return 1; // Sucesso
}

int pilha_vazia(Pilha *p) {
    return p->topo == -1;
}

int pilha_cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int tamanho_pilha(Pilha *p) {
    return p->topo + 1;
}
