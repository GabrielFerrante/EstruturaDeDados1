#include "pilha.h"

void inicializar(PilhaEstatica *pilha) {
    pilha->topo = -1; //lembrando, o topo -1 é por que a pilha não tem nenhum elemento.
}

int empilhar(PilhaEstatica *pilha, int valor) {
    if (esta_cheia(pilha)) {
        return 0; // Falha ao empilhar - pilha cheia
    }
    
    pilha->dados[++pilha->topo] = valor; //++pilha->topo quer dizer que o index do topo aumentou antes do valor ser inserido de fato.
    return 1; // Sucesso ao empilhar
}

int desempilhar(PilhaEstatica *pilha, int *valor) {
    if (esta_vazia(pilha)) {
        return 0; // Falha ao desempilhar - pilha vazia
    }
    
    *valor = pilha->dados[pilha->topo--]; //note que pilha->topo-- já decrementa o valor do index do topo após o resgate do valor
    return 1; // Sucesso ao desempilhar
}

int topo(PilhaEstatica *pilha, int *valor) {
    if (esta_vazia(pilha)) {
        return 0; // Falha - pilha vazia
    }
    
    *valor = pilha->dados[pilha->topo];
    return 1; // Sucesso
}

int esta_vazia(PilhaEstatica *pilha) {
    return pilha->topo == -1;
}

int esta_cheia(PilhaEstatica *pilha) {
    return pilha->topo == MAX - 1;
}

int tamanho(PilhaEstatica *pilha) {
    return pilha->topo + 1;
}
