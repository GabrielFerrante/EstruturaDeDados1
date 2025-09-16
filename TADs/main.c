#include <stdio.h>
#include "ponto.c"

int main() {
    // Criando pontos
    Ponto* p1 = ponto_criar(3.0, 4.0);
    Ponto* p2 = ponto_criar(1.0, 2.0);
    Ponto* p3 = ponto_criar(0.0, 0.0);
    
    printf("Pontos criados:\n");
    printf("p1 = ");
    ponto_imprimir(p1);
    printf("p2 = ");
    ponto_imprimir(p2);
    printf("p3 = ");
    ponto_imprimir(p3);
    
    // Calculando distâncias
    printf("\nDistancias entre p1 e p2:\n");
    printf("Euclidiana: %.2f\n", distancia_euclidiana(p1, p2));
    printf("Manhattan: %.2f\n", distancia_manhattan(p1, p2));
    printf("Similaridade do Cosseno: %.2f\n", distancia_cosseno(p1, p2));
    
    printf("\nDistancias entre p1 e p3:\n");
    printf("Euclidiana: %.2f\n", distancia_euclidiana(p1, p3));
    printf("Manhattan: %.2f\n", distancia_manhattan(p1, p3));
    printf("Similaridade do Cosseno: %.2f\n", distancia_cosseno(p1, p3));
    
    // Testando getters e setters
    printf("\nTestando getters e setters:\n");
    printf("Coordenada x de p1: %.2f\n", ponto_get_x(p1));
    printf("Coordenada y de p1: %.2f\n", ponto_get_y(p1));
    
    ponto_set_x(p1, 5.0);
    ponto_set_y(p1, 6.0);
    printf("p1 apos modificacao: ");
    ponto_imprimir(p1);
    
    // Calculando produto escalar e magnitude
    printf("\nProduto escalar entre p1 e p2: %.2f\n", produto_escalar(p1, p2));
    printf("Magnitude de p1: %.2f\n", magnitude(p1));
    printf("Magnitude de p2: %.2f\n", magnitude(p2));
    
    // Liberando memória
    ponto_destruir(p1);
    ponto_destruir(p2);
    ponto_destruir(p3);
    
    return 0;
}
