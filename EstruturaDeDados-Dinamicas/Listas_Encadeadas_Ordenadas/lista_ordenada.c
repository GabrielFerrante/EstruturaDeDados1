#include "lista_ordenada.h"
#include <stdlib.h>
#include <stdio.h>

void inicializar(ListaOrdenada* lista) {
    lista->inicio = NULL;
}

No* search(ListaOrdenada* lista, int chave) {
    No* atual = lista->inicio;
    
    while (atual != NULL && atual->chave <= chave) {
        if (atual->chave == chave) {
            return atual; // Encontrou
        }
        atual = atual->proximo;
    }
    
    return NULL; // Não encontrou
}

void insert(ListaOrdenada* lista, int chave) {
    No* current = lista->inicio;
    No* previous = NULL;
    
    while (current != NULL) {
        if (current->chave > chave) {
            break;
        } else {
            previous = current;
            current = current->proximo;
        }
    }
    
    No* temp = (No*)malloc(sizeof(No));
    temp->chave = chave;
    
    if (previous == NULL) {
        temp->proximo = lista->inicio;
        lista->inicio = temp;
    } else {
        temp->proximo = current;
        previous->proximo = temp;
    }
}

int remove_node(ListaOrdenada* lista, int chave) {
    No* current = lista->inicio;
    No* previous = NULL;
    
    while (current != NULL) {
        if (current->chave == chave) {
            // Encontrou o nó a ser removido
            if (previous == NULL) {
                // Remove do início
                lista->inicio = current->proximo;
            } else {
                // Remove do meio/fim
                previous->proximo = current->proximo;
            }
            free(current);
            return 1; // Remoção bem-sucedida
        }
        previous = current;
        current = current->proximo;
    }
    
    return 0; // Chave não encontrada
}

void imprimir(ListaOrdenada* lista) {
    No* atual = lista->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    }
    printf("\n");
}

void liberar(ListaOrdenada* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
}
