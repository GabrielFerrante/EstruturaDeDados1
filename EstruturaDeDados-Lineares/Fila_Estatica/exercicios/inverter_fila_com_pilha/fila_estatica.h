#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int frente;
    int tras;
    int tamanho;
} Fila;

void inicializar_fila(Fila *f);
int enfileirar(Fila *f, int elemento);
int desenfileirar(Fila *f, int *elemento);
int frente_fila(Fila *f, int *elemento);
int fila_vazia(Fila *f);
int fila_cheia(Fila *f);
int tamanho_fila(Fila *f);
void imprimir_fila(Fila *f);
void inverter_fila(Fila *f);

#endif
