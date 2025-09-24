#include <stdio.h>
#include "pilha.c"
#include "reorganiza.c"
#include <locale.h>
void testar_reorganizacao(int elementos[], int tamanho) {
    Pilha original;
    inicializar(&original);
    int i = 0;
    // Empilha os elementos na ordem fornecida
    for (i = 0; i < tamanho; i++) {
        empilhar(&original, elementos[i]);
    }
    
    printf("=== TESTE ===\n");
    printf("Pilha antes da reorganização:\n");
    imprimir_pilha(&original);
    
    reorganizar_pilha(&original);
    
    printf("Pilha após a reorganização:\n");
    imprimir_pilha(&original);
    printf("\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    printf("=== REORGANIZADOR DE PILHA ===\n");
    printf("(Negativos na base, positivos no topo)\n\n");
    
    // Teste 1: Caso simples
    int teste1[] = {1, -2, 3, -4, 5};
    testar_reorganizacao(teste1, 5);
    
    // Teste 2: Apenas positivos
    int teste2[] = {1, 2, 3, 4, 5};
    testar_reorganizacao(teste2, 5);
    
    // Teste 3: Apenas negativos
    int teste3[] = {-1, -2, -3, -4, -5};
    testar_reorganizacao(teste3, 5);
    
    // Teste 4: Misturado
    int teste4[] = {10, -5, 7, -3, 0, -8, 15};
    testar_reorganizacao(teste4, 7);
    
    // Teste 5: Com zeros
    int teste5[] = {0, -1, 0, 2, -3, 0};
    testar_reorganizacao(teste5, 6);
    
    // Teste interativo
    printf("=== TESTE INTERATIVO ===\n");
    printf("Digite os elementos da pilha (um por linha, -999 para terminar):\n");
    
    Pilha interativa;
    inicializar(&interativa);
    
    int elemento;
    while (1) {
        printf("Elemento: ");
        scanf("%d", &elemento);
        
        if (elemento == -999) break;
        
        if (!empilhar(&interativa, elemento)) {
            printf("Erro: Pilha cheia!\n");
            break;
        }
    }
    
    if (!esta_vazia(&interativa)) {
        printf("\nPilha inserida:\n");
        imprimir_pilha(&interativa);
        
        reorganizar_pilha(&interativa);
        
        printf("Resultado final:\n");
        imprimir_pilha(&interativa);
    }
    
    return 0;
}
