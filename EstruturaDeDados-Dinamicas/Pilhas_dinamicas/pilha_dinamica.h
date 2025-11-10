#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
} PilhaDinamica;

void inicializar(PilhaDinamica* pilha);
void empilhar(PilhaDinamica* pilha, int valor);
int desempilhar(PilhaDinamica* pilha);
int vazia(PilhaDinamica* pilha);

#endif
