#ifndef LISTA_H
#define LISTA_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} Lista;

// Funções básicas
Lista* criar_lista();
void destruir_lista(Lista* lista);
int esta_vazia(Lista* lista);
int tamanho(Lista* lista);

// Inserção
void inserir_inicio(Lista* lista, int valor);
void inserir_fim(Lista* lista, int valor);
void inserir_posicao(Lista* lista, int valor, int posicao);

// Remoção
int remover_inicio(Lista* lista);
int remover_fim(Lista* lista);
int remover_posicao(Lista* lista, int posicao);

// Busca e acesso
int buscar_elemento(Lista* lista, int valor);
int acessar_posicao(Lista* lista, int posicao);

// Impressão
void imprimir_lista(Lista* lista);

#endif
