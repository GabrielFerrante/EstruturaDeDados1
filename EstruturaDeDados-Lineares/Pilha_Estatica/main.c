#include <stdio.h>
#include "pilha.c" //Note que antigamente, a linguagem C aceitava o arquivo .h aqui, por�m, na nova vers�o podemos importar o .c 
// com as opera��es, mas ainda � obrigat�rio que exista o cabe�alho .h correspondente.

int main() {
    PilhaEstatica pilha;
    int valor; //Essa variavel � uma variavel auxiliar que vai ficar assumindo o valor para os printfs.
    
    inicializar(&pilha);
    
    // Empilhando valores
    printf("Empilhando valores:\n");
    int i = 1; // Note que aqui � uma obrigatoriedade das novas vers�es da linguagem C, que n�o permite atribui��o da variavel de controle do for nele mesmo.
    for (i = 1; i <= 5; i++) {
        if (empilhar(&pilha, i * 10)) {
            printf("Empilhado: %d\n", i * 10);
        } else {
            printf("Erro: pilha cheia!\n");
        }
    }
    
    // Verificando o topo
    if (topo(&pilha, &valor)) {
        printf("\nTopo da pilha: %d\n", valor);
    }
    
    // Verificando tamanho
    printf("Tamanho da pilha: %d\n", tamanho(&pilha));
    
    // Desempilhando valores
    printf("\nDesempilhando valores:\n");
    while (desempilhar(&pilha, &valor)) {
        printf("Desempilhado: %d\n", valor);
    }
    
    // Tentando desempilhar pilha vazia
    if (!desempilhar(&pilha, &valor)) {
        printf("\nPilha vazia - nao eh possivel desempilhar\n");
    }
    
    // Testando pilha cheia
    printf("\nTestando capacidade maxima:\n");
    i = 0;
    for (i = 0; i < MAX + 2; i++) {
        if (!empilhar(&pilha, i)) {
            printf("Pilha cheia no elemento %d\n", i);
            break;
        }
    }
    
    return 0;
}
