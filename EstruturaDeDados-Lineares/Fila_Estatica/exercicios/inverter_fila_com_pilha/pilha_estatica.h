#ifndef PILHA_ESTATICA_H
#define PILHA_ESTATICA_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *p);
int empilhar(Pilha *p, int elemento);
int desempilhar(Pilha *p, int *elemento);
int topo_pilha(Pilha *p, int *elemento);
int pilha_vazia(Pilha *p);
int pilha_cheia(Pilha *p);
int tamanho_pilha(Pilha *p);

#endif
