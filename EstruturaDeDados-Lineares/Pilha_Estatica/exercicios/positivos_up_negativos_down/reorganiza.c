#include <stdio.h>

#include "reorganiza.h"

void reorganizar_pilha(Pilha *original) {
    Pilha positivos, negativos, temp;
    int elemento;
    
    // Inicializa as pilhas auxiliares
    inicializar(&positivos);
    inicializar(&negativos);
    inicializar(&temp);
    
    printf("\n=== INÍCIO DA REORGANIZAÇÃO ===\n");
    printf("Pilha original: ");
    imprimir_pilha(original);
    
    // Passo 1: Desempilha a pilha original para uma pilha temporária
    // Isso inverte a ordem, mas vamos corrigir depois
    while (!esta_vazia(original)) {
        desempilhar(original, &elemento);
        empilhar(&temp, elemento);
    }
    
    printf("Pilha temporária: ");
    imprimir_pilha(&temp);
    
    // Passo 2: Separa os elementos nas pilhas de positivos e negativos
    while (!esta_vazia(&temp)) {
        desempilhar(&temp, &elemento);
        
        if (elemento >= 0) {
            empilhar(&positivos, elemento);
        } else {
            empilhar(&negativos, elemento);
        }
    }
    
    printf("Pilha de positivos: ");
    imprimir_pilha(&positivos);
    printf("Pilha de negativos: ");
    imprimir_pilha(&negativos);
    
    // Passo 3: Empilha os negativos primeiro (ficarão na base)
    while (!esta_vazia(&negativos)) {
        desempilhar(&negativos, &elemento);
        empilhar(&temp, elemento); // Usa temp para inverter a ordem dos negativos
    }
    
    // Agora empilha os negativos na ordem correta na original
    while (!esta_vazia(&temp)) {
        desempilhar(&temp, &elemento);
        empilhar(original, elemento);
    }
    
    // Passo 4: Empilha os positivos (ficarão no topo)
    while (!esta_vazia(&positivos)) {
        desempilhar(&positivos, &elemento);
        empilhar(&temp, elemento); // Usa temp para inverter a ordem dos positivos
    }
    
    // Agora empilha os positivos na ordem correta na original
    while (!esta_vazia(&temp)) {
        desempilhar(&temp, &elemento);
        empilhar(original, elemento);
    }
    
    printf("Pilha reorganizada: ");
    imprimir_pilha(original);
    printf("=== FIM DA REORGANIZAÇÃO ===\n\n");
}
