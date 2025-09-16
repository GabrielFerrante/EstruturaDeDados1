#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

// Definição da estrutura (implementação oculta)
struct ponto {
    float x;
    float y;
};

// Cria um novo ponto
Ponto* ponto_criar(float x, float y) {
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

// Libera a memoria alocada para o ponto
void ponto_destruir(Ponto* p) {
    free(p);
}

// Imprime o ponto no formato (x, y)
void ponto_imprimir(Ponto* p) {
    printf("(%.2f, %.2f)\n", p->x, p->y);
}

// Getters e Setters
//ESTES MÉTODOS SAO FORMAS DE USARMOS FUNÇÕES BASICAS PARA PEGAR OS ATRIBUTOS DE UMA STRUCT  
// GET PARA PEGAR
// SET PARA DEFINIR
// ISSO NORMALMENTE EH UM ESBOÇO DO QUE É FEITO NA PROGRAMACAO ORIENTADA A OBJETOS.
float ponto_get_x(Ponto* p) {
    return p->x;
}

float ponto_get_y(Ponto* p) {
    return p->y;
}

void ponto_set_x(Ponto* p, float x) {
    p->x = x;
}

void ponto_set_y(Ponto* p, float y) {
    p->y = y;
}

// Calcula a distancia euclidiana entre dois pontos
float distancia_euclidiana(Ponto* p1, Ponto* p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

// Calcula a distancia de Manhattan entre dois pontos
float distancia_manhattan(Ponto* p1, Ponto* p2) {
    return fabs(p1->x - p2->x) + fabs(p1->y - p2->y);
}

// Calcula a similaridade do cosseno entre dois pontos (tratados como vetores)
float distancia_cosseno(Ponto* p1, Ponto* p2) {
    float produto = produto_escalar(p1, p2);
    float mag1 = magnitude(p1);
    float mag2 = magnitude(p2);
    
    if (mag1 == 0 || mag2 == 0) {
        return 0; // Evita divisao por zero
    }
    
    return produto / (mag1 * mag2);
}

// Calcula o produto escalar entre dois pontos (tratados como vetores)
float produto_escalar(Ponto* p1, Ponto* p2) {
    return p1->x * p2->x + p1->y * p2->y;
}

// Calcula a magnitude (comprimento) de um ponto (tratado como vetor)
float magnitude(Ponto* p) {
    return sqrt(p->x * p->x + p->y * p->y);
}