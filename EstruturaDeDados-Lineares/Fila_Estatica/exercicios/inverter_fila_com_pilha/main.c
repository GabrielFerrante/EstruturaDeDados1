#include <stdio.h>
#include "fila_estatica.c"
#include <locale.h>
void demonstrar_inversao_basica() {
    printf("=== DEMONSTRA��O B�SICA DA INVERS�O ===\n");
    
    Fila fila;
    inicializar_fila(&fila);
    
    // Enfileira alguns elementos
    int i = 1;
    for (i = 1; i <= 5; i++) {
        enfileirar(&fila, i * 10);
    }
    
    printf("Fila antes da invers�o:\n");
    imprimir_fila(&fila);
    
    // Inverte a fila
    inverter_fila(&fila);
    
    printf("Fila ap�s invers�o:\n");
    imprimir_fila(&fila);
}

void testar_inversao_vazia() {
    printf("\n=== TESTE COM FILA VAZIA ===\n");
    
    Fila fila;
    inicializar_fila(&fila);
    
    printf("Fila antes da invers�o:\n");
    imprimir_fila(&fila);
    
    inverter_fila(&fila);
    
    printf("Fila ap�s invers�o:\n");
    imprimir_fila(&fila);
}

void testar_inversao_um_elemento() {
    printf("\n=== TESTE COM UM ELEMENTO ===\n");
    
    Fila fila;
    inicializar_fila(&fila);
    
    enfileirar(&fila, 42);
    
    printf("Fila antes da invers�o:\n");
    imprimir_fila(&fila);
    
    inverter_fila(&fila);
    
    printf("Fila ap�s invers�o:\n");
    imprimir_fila(&fila);
}

void testar_inversao_multipla() {
    printf("\n=== TESTE COM M�LTIPLAS INVERS�ES ===\n");
    
    Fila fila;
    inicializar_fila(&fila);
    
    // Enfileira elementos
    int i = 1;
    for (i = 1; i <= 3; i++) {
        enfileirar(&fila, i);
    }
    
    printf("Estado inicial:\n");
    imprimir_fila(&fila);
    
    // Primeira invers�o
    inverter_fila(&fila);
    printf("Ap�s primeira invers�o:\n");
    imprimir_fila(&fila);
    
    // Segunda invers�o (dever� voltar ao original)
    inverter_fila(&fila);
    printf("Ap�s segunda invers�o (deveria voltar ao original):\n");
    imprimir_fila(&fila);
}

void menu_interativo() {
    printf("\n=== MENU INTERATIVO ===\n");
    
    Fila fila;
    inicializar_fila(&fila);
    
    int opcao, elemento;
    
    do {
        printf("\n--- Menu de Opera��es ---\n");
        printf("1. Enfileirar elemento\n");
        printf("2. Desenfileirar elemento\n");
        printf("3. Ver frente da fila\n");
        printf("4. Imprimir fila\n");
        printf("5. Inverter fila\n");
        printf("6. Verificar se fila est� vazia\n");
        printf("7. Ver tamanho da fila\n");
        printf("0. Sair\n");
        printf("Op��o: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Elemento para enfileirar: ");
                scanf("%d", &elemento);
                if (enfileirar(&fila, elemento)) {
                    printf("Elemento %d enfileirado com sucesso!\n", elemento);
                } else {
                    printf("Erro: Fila cheia!\n");
                }
                break;
                
            case 2:
                if (desenfileirar(&fila, &elemento)) {
                    printf("Elemento %d desenfileirado!\n", elemento);
                } else {
                    printf("Erro: Fila vazia!\n");
                }
                break;
                
            case 3:
                if (frente_fila(&fila, &elemento)) {
                    printf("Elemento na frente: %d\n", elemento);
                } else {
                    printf("Fila vazia!\n");
                }
                break;
                
            case 4:
                imprimir_fila(&fila);
                break;
                
            case 5:
                inverter_fila(&fila);
                break;
                
            case 6:
                printf("Fila est� vazia? %s\n", fila_vazia(&fila) ? "Sim" : "N�o");
                break;
                
            case 7:
                printf("Tamanho da fila: %d\n", tamanho_fila(&fila));
                break;
                
            case 0:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 0);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    printf("=== ALGORITMO DE INVERS�O DE FILA USANDO PILHA ===\n\n");
    
    demonstrar_inversao_basica();
    testar_inversao_vazia();
    testar_inversao_um_elemento();
    testar_inversao_multipla();
    menu_interativo();
    
    return 0;
}
