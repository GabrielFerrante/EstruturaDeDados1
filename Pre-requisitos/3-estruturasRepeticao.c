#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main() {
	
	setlocale(LC_ALL, "");
    // Exemplo 1: Estrutura de repetição 'for'
    printf("Exemplo de for:\n");
    int i = 0;
    for (i = 0; i < 5; i++) {
        printf("for: i = %d\n", i);
    }

    // Exemplo 2: Estrutura de repetição 'while'
    printf("\nExemplo de while:\n");
    int j = 0;
    while (j < 5) {
        printf("while: j = %d\n", j);
        j++;
    }

    // Exemplo 3: Estrutura de repetição 'do...while'
    printf("\nExemplo de do...while:\n");
    int k = 0;
    do {
        printf("do...while: k = %d\n", k);
        k++;
    } while (k < 5);

    // Exemplo 4: Estrutura de repetição infinita (loop infinito)
    // Atenção: Este exemplo está comentado para evitar travar o programa.
    /*
    printf("\nExemplo de loop infinito:\n");
    while (1) {
        printf("Este loop nunca termina!\n");
        break; // Remova o break para ver o loop infinito
    }
    */

    // Exemplo 5: Uso de break e continue
    printf("\nExemplo de break e continue:\n");
    int m = 0;
    for (m = 0; m < 5; m++) {
        if (m == 2) {
            printf("break quando m == 2\n");
            break;
        }
        if (m == 1) {
            printf("continue quando m == 1\n");
            continue;
        }
        printf("m = %d\n", m);
    }

    return 0;
}

/*
Resumo das estruturas de repetição em C:
1. for (inicialização; condição; incremento) { ... }
2. while (condição) { ... }
3. do { ... } while (condição);
4. while (1) { ... } // loop infinito
5. break e continue para controle de fluxo dentro dos loops
*/
