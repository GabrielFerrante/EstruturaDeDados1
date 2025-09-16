#ifndef PILHA_ESTATICA_H
#define PILHA_ESTATICA_H

#define MAX 100 // Tamanho maximo da pilha

//A conven��o atual de cria��o de structs em linguagem C � no arquivo de cabe�alho.
typedef struct {
    int dados[MAX];
    int topo;
} PilhaEstatica;

void inicializar(PilhaEstatica *pilha);
int empilhar(PilhaEstatica *pilha, int valor);
int desempilhar(PilhaEstatica *pilha, int *valor);
int topo(PilhaEstatica *pilha, int *valor);
int esta_vazia(PilhaEstatica *pilha);
int esta_cheia(PilhaEstatica *pilha);
int tamanho(PilhaEstatica *pilha);

#endif
