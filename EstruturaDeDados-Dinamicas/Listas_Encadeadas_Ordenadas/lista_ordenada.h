#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H

typedef struct No {
    int chave;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
} ListaOrdenada;

void inicializar(ListaOrdenada* lista);
No* search(ListaOrdenada* lista, int chave);
void insert(ListaOrdenada* lista, int chave);
int remove_node(ListaOrdenada* lista, int chave);
void imprimir(ListaOrdenada* lista);
void liberar(ListaOrdenada* lista);

#endif
