#include <stdio.h>
#include "fila_estatica.h"
#include "pilha_estatica.c"

void inicializar_fila(Fila *f) {
    f->frente = 0;
    f->tras = 0;
    f->tamanho = 0;
}

int enfileirar(Fila *f, int elemento) {
    if (fila_cheia(f)) {
        return 0; // Falha - fila cheia
    }
    f->dados[f->tras] = elemento;
    f->tras = (f->tras + 1) % MAX;
    f->tamanho++;
    return 1; // Sucesso
}

int desenfileirar(Fila *f, int *elemento) {
    if (fila_vazia(f)) {
        return 0; // Falha - fila vazia
    }
    *elemento = f->dados[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return 1; // Sucesso
}

int frente_fila(Fila *f, int *elemento) {
    if (fila_vazia(f)) {
        return 0; // Falha - fila vazia
    }
    *elemento = f->dados[f->frente];
    return 1; // Sucesso
}

int fila_vazia(Fila *f) {
    return f->tamanho == 0;
}

int fila_cheia(Fila *f) {
    return f->tamanho == MAX;
}

int tamanho_fila(Fila *f) {
    return f->tamanho;
}

void imprimir_fila(Fila *f) {
    if (fila_vazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    
    printf("Fila (frente -> tras): ");
    int i = f->frente;
    int count = 0;
    for (count = 0; count < f->tamanho; count++) {
        printf("%d ", f->dados[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Função principal que inverte a fila usando uma pilha
void inverter_fila(Fila *f) {
    Pilha S;
    inicializar_pilha(&S);
    int elemento;
    
    printf("\n=== INICIANDO INVERSÃO DA FILA ===\n");
    printf("Fila original: ");
    imprimir_fila(f);
    
    // Passo 1: Desenfileira todos os elementos da fila e empilha na pilha
    printf("\nPasso 1: Desenfileirando e empilhando...\n");
    while (!fila_vazia(f)) {
        desenfileirar(f, &elemento);
        empilhar(&S, elemento);
        printf("  Desenfileirado %d e empilhado\n", elemento);
    }
    
    printf("Pilha após empilhamento: ");
    if (!pilha_vazia(&S)) {
        // Para imprimir a pilha (do topo para a base)
        Pilha temp = S;
        printf("Pilha (topo -> base): ");
        while (!pilha_vazia(&temp)) {
            int elem;
            desempilhar(&temp, &elem);
            printf("%d ", elem);
        }
        printf("\n");
    }
    
    // Passo 2: Desempilha todos os elementos da pilha e enfileira na fila
    printf("\nPasso 2: Desempilhando e enfileirando...\n");
    while (!pilha_vazia(&S)) {
        desempilhar(&S, &elemento);
        enfileirar(f, elemento);
        printf("  Desempilhado %d e enfileirado\n", elemento);
    }
    
    printf("Fila após inversão: ");
    imprimir_fila(f);
    printf("=== INVERSÃO CONCLUÍDA ===\n\n");
}
