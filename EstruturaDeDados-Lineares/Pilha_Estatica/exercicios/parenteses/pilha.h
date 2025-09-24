#ifndef PILHA_H
#define PILHA_H

#define MAX 100

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p);
int empilhar(Pilha *p, char elemento);
int desempilhar(Pilha *p, char *elemento);
int topo(Pilha *p, char *elemento);
int esta_vazia(Pilha *p);
int esta_cheia(Pilha *p);

#endif
