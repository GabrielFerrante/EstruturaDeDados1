#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista* criar_lista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista == NULL) {
        printf("Erro ao alocar memória para a lista!\n");
        return NULL;
    }
    lista->head = NULL;
    lista->size = 0;
    return lista;
}

void destruir_lista(Lista* lista) {
    if (lista == NULL) return;
    
    Node* atual = lista->head;
    while (atual != NULL) {
        Node* proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    free(lista);
}

int esta_vazia(Lista* lista) {
    return lista == NULL || lista->head == NULL;
}

int tamanho(Lista* lista) {
    if (lista == NULL) return 0;
    return lista->size;
}

void inserir_inicio(Lista* lista, int valor) {
    if (lista == NULL) return;
    
    Node* novo_node = (Node*)malloc(sizeof(Node));
    if (novo_node == NULL) {
        printf("Erro ao alocar memória para novo nó!\n");
        return;
    }
    
    novo_node->data = valor;
    novo_node->next = lista->head;
    lista->head = novo_node;
    lista->size++;
}

void inserir_fim(Lista* lista, int valor) {
    if (lista == NULL) return;
    
    Node* novo_node = (Node*)malloc(sizeof(Node));
    if (novo_node == NULL) {
        printf("Erro ao alocar memória para novo nó!\n");
        return;
    }
    
    novo_node->data = valor;
    novo_node->next = NULL;
    
    if (esta_vazia(lista)) {
        lista->head = novo_node;
    } else {
        Node* atual = lista->head;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novo_node;
    }
    lista->size++;
}

void inserir_posicao(Lista* lista, int valor, int posicao) {
    if (lista == NULL || posicao < 0 || posicao > lista->size) {
        printf("Posição inválida!\n");
        return;
    }
    
    if (posicao == 0) {
        inserir_inicio(lista, valor);
        return;
    }
    
    if (posicao == lista->size) {
        inserir_fim(lista, valor);
        return;
    }
    
    Node* novo_node = (Node*)malloc(sizeof(Node));
    if (novo_node == NULL) {
        printf("Erro ao alocar memória para novo nó!\n");
        return;
    }
    novo_node->data = valor;
    
    Node* atual = lista->head;
    int i = 0;
    for (i = 0; i < posicao - 1; i++) {
        atual = atual->next;
    }
    
    novo_node->next = atual->next;
    atual->next = novo_node;
    lista->size++;
}

int remover_inicio(Lista* lista) {
    if (esta_vazia(lista)) {
        printf("Lista vazia!\n");
        return -1;
    }
    
    Node* temp = lista->head;
    int valor = temp->data;
    lista->head = lista->head->next;
    free(temp);
    lista->size--;
    return valor;
}

int remover_fim(Lista* lista) {
    if (esta_vazia(lista)) {
        printf("Lista vazia!\n");
        return -1;
    }
    
    if (lista->head->next == NULL) {
        return remover_inicio(lista);
    }
    
    Node* atual = lista->head;
    while (atual->next->next != NULL) {
        atual = atual->next;
    }
    
    int valor = atual->next->data;
    free(atual->next);
    atual->next = NULL;
    lista->size--;
    return valor;
}

int remover_posicao(Lista* lista, int posicao) {
    if (esta_vazia(lista) || posicao < 0 || posicao >= lista->size) {
        printf("Posição inválida!\n");
        return -1;
    }
    
    if (posicao == 0) {
        return remover_inicio(lista);
    }
    
    if (posicao == lista->size - 1) {
        return remover_fim(lista);
    }
    
    Node* atual = lista->head;
    int i = 0;
    for (i = 0; i < posicao - 1; i++) {
        atual = atual->next;
    }
    
    Node* temp = atual->next;
    int valor = temp->data;
    atual->next = temp->next;
    free(temp);
    lista->size--;
    return valor;
}

int buscar_elemento(Lista* lista, int valor) {
    if (esta_vazia(lista)) {
        return -1;
    }
    
    Node* atual = lista->head;
    int posicao = 0;
    
    while (atual != NULL) {
        if (atual->data == valor) {
            return posicao;
        }
        atual = atual->next;
        posicao++;
    }
    
    return -1; // Não encontrado
}

int acessar_posicao(Lista* lista, int posicao) {
    if (esta_vazia(lista) || posicao < 0 || posicao >= lista->size) {
        printf("Posição inválida!\n");
        return -1;
    }
    
    Node* atual = lista->head;
    int i = 0;
    for (i = 0; i < posicao; i++) {
        atual = atual->next;
    }
    
    return atual->data;
}

void imprimir_lista(Lista* lista) {
    if (esta_vazia(lista)) {
        printf("Lista vazia!\n");
        return;
    }
    
    Node* atual = lista->head;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d", atual->data);
        if (atual->next != NULL) {
            printf(" -> ");
        }
        atual = atual->next;
    }
    printf("\n");
}
