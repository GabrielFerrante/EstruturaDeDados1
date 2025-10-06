#include <stdio.h>
#include "fila_estatica.c"
#include <locale.h>

void demonstrar_operacoes_basicas() {
    printf("=== OPERAÇÕES BÁSICAS ===\n");
    Fila fila;
    inicializar(&fila);
    
    // Enfileirando elementos
    printf("Enfileirando elementos:\n");
    int i = 1;
    for (i = 1; i <= 5; i++) {
        if (enqueue(&fila, i * 10)) {
            printf("Enfileirado: %d\n", i * 10);
        }
    }
    imprimir_fila(&fila);
    printf("Tamanho da fila: %d\n", tamanho(&fila));
    
    // Verificando a frente
    int elem_frente;
    if (frente(&fila, &elem_frente)) {
        printf("Elemento na frente: %d\n", elem_frente);
    }
    
    // Desenfileirando elementos
    printf("\nDesenfileirando elementos:\n");
    int elemento;
    while (dequeue(&fila, &elemento)) {
        printf("Desenfileirado: %d\n", elemento);
    }
    imprimir_fila(&fila);
}

void testar_fila_circular() {
    printf("\n=== TESTE DA FILA CIRCULAR ===\n");
    Fila fila;
    inicializar(&fila);
    
    // Preenche a fila parcialmente
    int i = 1;
    for (i = 1; i <= 3; i++) {
        enqueue(&fila, i);
    }
    printf("Fila inicial: ");
    imprimir_fila(&fila);
    
    // Simula operaçõess que demonstram o comportamento circular
    int elemento;
    dequeue(&fila, &elemento);
    printf("Desenfileirado: %d\n", elemento);
    
    enqueue(&fila, 10);
    printf("Após enfileirar 10: ");
    imprimir_fila(&fila);
    
    dequeue(&fila, &elemento);
    printf("Desenfileirado: %d\n", elemento);
    
    enqueue(&fila, 20);
    printf("Após enfileirar 20: ");
    imprimir_fila(&fila);
}

void testar_capacidade_maxima() {
    printf("\n=== TESTE DE CAPACIDADE MÁXIMA ===\n");
    Fila fila;
    inicializar(&fila);
    
    printf("Preenchendo fila até a capacidade máxima...\n");
    int i = 1;
    for (i = 1; i <= MAX + 5; i++) {
        if (!enqueue(&fila, i)) {
            printf("Fila cheia no elemento %d\n", i);
            break;
        }
    }
    
    printf("Tamanho da fila: %d\n", tamanho(&fila));
    printf("Fila está cheia? %s\n", esta_cheia(&fila) ? "Sim" : "Não");
    
    // Esvazia a fila
    int elemento;
    while (dequeue(&fila, &elemento)) {
        // Apenas desenfileira
    }
    printf("Fila irá esvaziar: ");
    imprimir_fila(&fila);
}

void menu_interativo() {
    printf("\n=== MENU INTERATIVO ===\n");
    Fila fila;
    inicializar(&fila);
    
    int opcao, elemento;
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Ver frente\n");
        printf("4. Ver tamanho\n");
        printf("5. Imprimir fila\n");
        printf("6. Verificar se está vazia\n");
        printf("7. Verificar se está cheia\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Elemento para enfileirar: ");
                scanf("%d", &elemento);
                if (enqueue(&fila, elemento)) {
                    printf("Elemento %d enfileirado com sucesso!\n", elemento);
                } else {
                    printf("Erro: Fila cheia!\n");
                }
                break;
                
            case 2:
                if (dequeue(&fila, &elemento)) {
                    printf("Elemento %d desenfileirado!\n", elemento);
                } else {
                    printf("Erro: Fila vazia!\n");
                }
                break;
                
            case 3:
                if (frente(&fila, &elemento)) {
                    printf("Elemento na frente: %d\n", elemento);
                } else {
                    printf("Fila vazia!\n");
                }
                break;
                
            case 4:
                printf("Tamanho da fila: %d\n", tamanho(&fila));
                break;
                
            case 5:
                imprimir_fila(&fila);
                break;
                
            case 6:
                printf("Fila está vazia? %s\n", esta_vazia(&fila) ? "Sim" : "Não");
                break;
                
            case 7:
                printf("Fila está cheia? %s\n", esta_cheia(&fila) ? "Sim" : "Não");
                break;
                
            case 0:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("=== IMPLEMENTAÇÃO DE FILA ESTÁTICA ===\n\n");
    
    demonstrar_operacoes_basicas();
    testar_fila_circular();
    testar_capacidade_maxima();
    menu_interativo();
    
    return 0;
}
