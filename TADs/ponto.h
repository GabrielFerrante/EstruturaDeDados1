#ifndef PONTO_H
#define PONTO_H

// Definição do tipo Ponto (estrutura opaca)
typedef struct ponto Ponto;

// Operações do TAD
Ponto* ponto_criar(float x, float y);
void ponto_destruir(Ponto* p);
void ponto_imprimir(Ponto* p);
float ponto_get_x(Ponto* p);
float ponto_get_y(Ponto* p);
void ponto_set_x(Ponto* p, float x);
void ponto_set_y(Ponto* p, float y);

// Funções de distância
float distancia_euclidiana(Ponto* p1, Ponto* p2);
float distancia_manhattan(Ponto* p1, Ponto* p2);
float distancia_cosseno(Ponto* p1, Ponto* p2);
float produto_escalar(Ponto* p1, Ponto* p2);
float magnitude(Ponto* p);

#endif