#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "batata_quente.c"
#include <locale.h>
void demonstrar_jogo_exemplo() {
    printf("=== DEMONSTRA��O DO JOGO ===\n\n");
    
    char *nomes[] = {"Ana", "Jo�o", "Maria", "Pedro", "Carla", "Lucas", "Julia", "Marcos"};
    int K = 8;
    int Max = 5;
    
    srand(time(NULL)); // Inicializa a semente para n�meros aleat�rios
    
    batata_quente(nomes, K, Max);
}

void jogo_personalizado() {
    printf("\n=== JOGO PERSONALIZADO ===\n");
    
    int K, Max;
    
    printf("Quantas crian�as v�o jogar? ");
    scanf("%d", &K);
    
    if (K <= 0 || K > MAX) {
        printf("N�mero inv�lido! Deve ser entre 1 e %d\n", MAX);
        return;
    }
    
    printf("N�mero m�ximo de passes: ");
    scanf("%d", &Max);
    
    if (Max <= 0) {
        printf("N�mero inv�lido! Deve ser maior que 0\n");
        return;
    }
    
    char **nomes = (char**)malloc(K * sizeof(char*));
    
    printf("Digite os nomes das crian�as:\n");
    int i = 0;
    for (i = 0; i < K; i++) {
        char nome[50];
        printf("Crian�a %d: ", i + 1);
        scanf("%s", nome);
        
        nomes[i] = (char*)malloc(50 * sizeof(char));
        sprintf(nomes[i], "%s", nome);
    }
    
    srand(time(NULL));
    batata_quente(nomes, K, Max);
    
    // Libera a mem�ria
    i = 0;
    for (i = 0; i < K; i++) {
        free(nomes[i]);
    }
    free(nomes);
}

void varios_testes() {
    printf("\n=== TESTES AUTOM�TICOS ===\n");
    
    srand(time(NULL));
    
    // Teste 1: Jogo pequeno
    printf("\n--- Teste 1: 3 crian�as, m�ximo 3 passes ---\n");
    char *teste1[] = {"Alice", "Bruno", "Carol"};
    batata_quente(teste1, 3, 3);
    
    // Teste 2: Jogo m�dio
    printf("\n--- Teste 2: 5 crian�as, m�ximo 5 passes ---\n");
    char *teste2[] = {"Ana", "Bia", "Carlos", "Duda", "Edu"};
    batata_quente(teste2, 5, 5);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    printf("=== JOGO DA BATATA QUENTE ===\n\n");
    
    int opcao;
    
    do {
        printf("Escolha uma op��o:\n");
        printf("1. Demonstra��o autom�tica\n");
        printf("2. Jogo personalizado\n");
        printf("3. Testes autom�ticos\n");
        printf("0. Sair\n");
        printf("Op��o: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                demonstrar_jogo_exemplo();
                break;
            case 2:
                jogo_personalizado();
                break;
            case 3:
                varios_testes();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
        }
        printf("\n");
    } while (opcao != 0);
    
    return 0;
}
