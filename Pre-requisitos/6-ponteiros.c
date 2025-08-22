#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
// Caso simples: ponteiro para variável comum
void exemploVariavel() {
    int x = 10;
    int *p = &x; // p aponta para x

    printf("Valor original de x: %d\n", x);
    *p = *p + 5; // Modifica x via ponteiro
    printf("Valor modificado de x: %d\n", x);
}
// Caso simples: ponteiro para array
void exemploArray() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr; // p aponta para o primeiro elemento do array

    printf("Array original:\n");
    int i = 0;
    for (i = 0; i < 5; i++) {
        printf("arr[%d] = %d, *(p + %d) = %d\n", i, arr[i], i, *(p + i));
    }

    // Modificando elementos via ponteiro
    for (i = 0; i < 5; i++) {
        *(p + i) = *(p + i) * 2;
    }

    printf("Array modificado:\n");
    for (i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

// Caso com matriz (array bidimensional)
void exemploMatriz() {
    int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int *p = &mat[0][0]; // p aponta para o primeiro elemento da matriz

    printf("\nMatriz original:\n");
    int i = 0;
    for (i = 0; i < 2; i++) {
    	int j = 0;
        for (j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n"); 
    }

    // Modificando elementos via ponteiro
    i = 0;
    for (i = 0; i < 6; i++) {
        *(p + i) = *(p + i) + 10;
    }

    printf("Matriz modificada:\n");
    i = 0;
    for (i = 0; i < 2; i++) {
    	int j = 0;
        for (j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Exemplo simples: ponteiro para função que soma dois inteiros
int soma(int a, int b) {
    return a + b;
}

// Função que recebe ponteiro para função

int calcula(int x, int y, int (*operacao)(int, int)) {
    return operacao(x, y);
}

// Exemplo de função que recebe ponteiro para função como argumento
void exemploPonteiroFuncao() {
    int (*pf)(int, int); // Declaração de ponteiro para função
    pf = soma; // pf aponta para a função soma

    int resultado = pf(3, 4); // Chama soma via ponteiro
    printf("Resultado da soma via ponteiro de fun��o: %d\n", resultado);

    // Usando ponteiro de função como argumento
    resultado = calcula(10, 20, soma);
    printf("Resultado de calcula usando ponteiro de fun��o: %d\n", resultado);
}


int main() {
	setlocale(LC_ALL, "");
    exemploVariavel();
    exemploArray();
    exemploMatriz();
    exemploPonteiroFuncao();
    return 0;
}
