#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int frente;
    int tras;
    int tamanho;
} Fila;

void inicializar(Fila *f);
int enfileirar(Fila *f, int elemento);
int desenfileirar(Fila *f, int *elemento);
int frente(Fila *f, int *elemento);
int esta_vazia(Fila *f);
int esta_cheia(Fila *f);
int tamanho(Fila *f);
void imprimir_fila(Fila *f);

#endif
