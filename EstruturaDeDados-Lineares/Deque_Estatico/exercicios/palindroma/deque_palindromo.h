#ifndef DEQUE_PALINDROMO_H
#define DEQUE_PALINDROMO_H

#define MAX 100

typedef struct {
    char dados[MAX];
    int frente;
    int tras;
    int tamanho;
} Deque;

// Operações do deque
void inicializar_deque(Deque *dq);
int deque_vazio(Deque *dq);
int deque_cheio(Deque *dq);
int tamanho_deque(Deque *dq);
int inserir_fim(Deque *dq, char elemento);
int inserir_inicio(Deque *dq, char elemento);
int remover_inicio(Deque *dq, char *elemento);
int remover_fim(Deque *dq, char *elemento);
int frente_deque(Deque *dq, char *elemento);
int fim_deque(Deque *dq, char *elemento);

// Função para verificar palíndromo
int eh_palindromo(char *palavra);

#endif
