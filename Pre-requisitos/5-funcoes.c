#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
// Função sem parâmetros e sem retorno
void saudacao() {
    printf("Ol�, mundo!\n");
}

// Função sem parâmetros e com retorno
int obterNumero() {
    return 42;
}

// Função com parâmetros e sem retorno
void imprimirSoma(int a, int b) {
    printf("A soma de %d e %d � %d\n", a, b, a + b);
}

// Função com parâmetros e com retorno
int multiplicar(int x, int y) {
    return x * y;
}

// Passagem de parâmetro por valor
void dobrarValor(int n) {
    n = n * 2;
    printf("Valor dobrado (por valor): %d\n", n);
}

// Passagem de parâmetro por referência
void dobrarReferencia(int *n) {
    *n = (*n) * 2;
    printf("Valor dobrado (por refer�ncia): %d\n", *n);
}

int main() {
	setlocale(LC_ALL, "");
    // Exemplo de chamada das funções
    saudacao();

    int numero = obterNumero();
    printf("N�mero obtido: %d\n", numero);

    imprimirSoma(5, 7);

    int produto = multiplicar(3, 4);
    printf("Produto: %d\n", produto);

    int n = 10;
    printf("Valor original de N: %d\n", n);
    dobrarValor(n);
    printf("Valor ap�s dobrar sem referencia de N: %d\n", n);
    dobrarReferencia(&n);
    printf("Valor ap�s dobrar passando a referencia de N: %d\n", n);
    



    return 0;
}
