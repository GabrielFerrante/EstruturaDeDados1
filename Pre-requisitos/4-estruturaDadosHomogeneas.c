#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main() {
	
	setlocale(LC_ALL, "");
    // Exemplo de Array (vetor)
    int numeros[5] = {10, 20, 30, 40, 50};
    printf("Array:\n");
    int i = 0;
    for (i = 0; i < 5; i++) {
        printf("numeros[%d] = %d\n", i, numeros[i]);
    }

    // Exemplo de Matriz (array bidimensional)
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("\nMatriz:\n");
    i = 0;
    for (i = 0; i < 2; i++) {
    	int j = 0;
        for (j = 0; j < 3; j++) {
            printf("matriz[%d][%d] = %d\n", i, j, matriz[i][j]);
        }
    }

    // Preenchendo um array com input do usuÃ¡rio
    int userArray[3];
    printf("\nPreencha o array com 3 números inteiros:\n");
    i = 0;
    for (i = 0; i < 3; i++) {
        printf("Digite o valor para userArray[%d]: ", i);
        scanf("%d", &userArray[i]);
    }
    printf("Array preenchido pelo usuário:\n");
    i = 0;
    for (i = 0; i < 3; i++) {
        printf("userArray[%d] = %d\n", i, userArray[i]);
    }

    // Preenchendo uma matriz com input do usuÃ¡rio
    int userMatriz[2][2];
    printf("\nPreencha a matriz 2x2 com números inteiros:\n");
    i = 0;
    for (i = 0; i < 2; i++) {
    	int j = 0;
        for (j = 0; j < 2; j++) {
            printf("Digite o valor para userMatriz[%d][%d]: ", i, j);
            scanf("%d", &userMatriz[i][j]);
        }
        
    }
    printf("Matriz preenchida pelo usuário:\n");
    i = 0;
    for (i = 0; i < 2; i++) {
    	int j = 0;
        for (j = 0; j < 2; j++) {
            printf("userMatriz[%d][%d] = %d\n", i, j, userMatriz[i][j]);
        }
    }

    return 0;
}
