#ifndef FILA_DINAMICA_H
#define FILA_DINAMICA_H

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* frente;
    No* tras;
} FilaDinamica;

void inicializar(FilaDinamica* fila);
void enfileirar(FilaDinamica* fila, int valor);
int desenfileirar(FilaDinamica* fila);
int vazia(FilaDinamica* fila);

#endif
