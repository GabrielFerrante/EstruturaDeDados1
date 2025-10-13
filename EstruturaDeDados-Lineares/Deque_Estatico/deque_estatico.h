#ifndef DEQUE_ESTATICO_H
#define DEQUE_ESTATICO_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int frente;
    int tras;
    int tamanho;
} Deque;

// Opera��es b�sicas
void inicializar_deque(Deque *dq);
int deque_vazio(Deque *dq);
int deque_cheio(Deque *dq);
int tamanho_deque(Deque *dq);

// Opera��es de inser��o
int inserir_frente(Deque *dq, int elemento);
int inserir_tras(Deque *dq, int elemento);

// Opera��es de remo��o
int remover_frente(Deque *dq, int *elemento);
int remover_tras(Deque *dq, int *elemento);

// Opera��es de consulta
int frente_deque(Deque *dq, int *elemento);
int tras_deque(Deque *dq, int *elemento);

// Utilidade
void imprimir_deque(Deque *dq);
void imprimir_deque_detalhado(Deque *dq);

#endif
