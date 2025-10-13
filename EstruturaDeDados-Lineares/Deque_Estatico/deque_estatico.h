#ifndef DEQUE_ESTATICO_H
#define DEQUE_ESTATICO_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int frente;
    int tras;
    int tamanho;
} Deque;

// Operações básicas
void inicializar_deque(Deque *dq);
int deque_vazio(Deque *dq);
int deque_cheio(Deque *dq);
int tamanho_deque(Deque *dq);

// Operações de inserção
int inserir_frente(Deque *dq, int elemento);
int inserir_tras(Deque *dq, int elemento);

// Operações de remoção
int remover_frente(Deque *dq, int *elemento);
int remover_tras(Deque *dq, int *elemento);

// Operações de consulta
int frente_deque(Deque *dq, int *elemento);
int tras_deque(Deque *dq, int *elemento);

// Utilidade
void imprimir_deque(Deque *dq);
void imprimir_deque_detalhado(Deque *dq);

#endif
