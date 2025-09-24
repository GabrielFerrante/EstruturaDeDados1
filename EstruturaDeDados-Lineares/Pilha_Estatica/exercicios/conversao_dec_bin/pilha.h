#ifndef PILHA_H
#define PILHA_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p);
int empilhar(Pilha *p, int elemento);
int desempilhar(Pilha *p, int *elemento);
int topo(Pilha *p, int *elemento);
int esta_vazia(Pilha *p);
int esta_cheia(Pilha *p);

#endif
