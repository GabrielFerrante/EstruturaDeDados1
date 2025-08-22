#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Operadores aritméticos: +, -, *, /, %
// Operadores l�gicos: && (E), || (OU), ! (NÃO)
// Operadores relacionais: >, <, >=, <=, ==, !=

int main() {
	setlocale(LC_ALL, "");
    int a = 10, b = 20, c = 15;

    // Exemplo 1: if simples
    if (a < b) {
        printf("a eh menor que b\n");
    }

    // Exemplo 2: if-else
    if (c % 2 == 0) {
        printf("c eh par\n");
    } else {
        printf("c eh impar\n");
    }

    // Exemplo 3: if-else if-else
    if (a + b > c) {
        printf("a + b eh maior que c\n");
    } else if (a + b == c) {
        printf("a + b eh igual a c\n");
    } else {
        printf("a + b eh menor que c\n");
    }

    // Exemplo 4: operadores lógicos
    if (a < b && b < c) {
        printf("a < b E b < c\n");
    }

    if (a < b || b > c) {
        printf("a < b OU b > c\n");
    }

    if (!(a == b)) {
        printf("a nao eh igual a b\n");
    }

    // Exercício 1: Verificar se um número está entre 10 e 20
    int x = 15;
    if (x >= 10 && x <= 20) {
        printf("x esta entre 10 e 20\n");
    } else {
        printf("x nao esta entre 10 e 20\n");
    }

    // Exercício 2: Verificar se um número é positivo, negativo ou zero
    int y = -5;
    if (y > 0) {
        printf("y eh positivo\n");
    } else if (y < 0) {
        printf("y eh negativo\n");
    } else {
        printf("y eh zero\n");
    }

    // Exercício 3: Verificar se um ano é bissexto
    int ano = 2024;
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        printf("%d eh bissexto\n", ano);
    } else {
        printf("%d nao eh bissexto\n", ano);
    }

    return 0;
}
