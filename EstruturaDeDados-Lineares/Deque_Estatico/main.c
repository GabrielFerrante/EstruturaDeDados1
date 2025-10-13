#include <stdio.h>
#include "deque_estatico.c"
#include <locale.h>

void demonstrar_operacoes_basicas() {
    printf("=== OPERAÇÕES BÁSICAS DO DEQUE ===\n");
    
    Deque dq;
    inicializar_deque(&dq);
    
    printf("Deque inicializado:\n");
    imprimir_deque_detalhado(&dq);
    
    // Inserções pela frente
    printf("\n--- Inserindo pela frente ---\n");
    int i = 1;
    for (i = 1; i <= 3; i++) {
        if (inserir_frente(&dq, i * 10)) {
            printf("Inserido %d pela frente\n", i * 10);
            imprimir_deque(&dq);
        }
    }
    
    // Inserções por trás
    printf("\n--- Inserindo por trás ---\n");
    i = 4;
    for (i = 4; i <= 6; i++) {
        if (inserir_tras(&dq, i * 10)) {
            printf("Inserido %d por trás\n", i * 10);
            imprimir_deque(&dq);
        }
    }
    
    imprimir_deque_detalhado(&dq);
    
    // Consultas
    printf("\n--- Consultas ---\n");
    int elemento;
    if (frente_deque(&dq, &elemento)) {
        printf("Elemento da frente: %d\n", elemento);
    }
    if (tras_deque(&dq, &elemento)) {
        printf("Elemento de trás: %d\n", elemento);
    }
    
    // Remoções pela frente
    printf("\n--- Removendo pela frente ---\n");
    while (remover_frente(&dq, &elemento)) {
        printf("Removido %d da frente\n", elemento);
        imprimir_deque(&dq);
    }
    
    // Reinicializar para demonstrar remoção por trás
    inicializar_deque(&dq);
	i = 1;
    for (i = 1; i <= 3; i++) {
        inserir_tras(&dq, i * 10);
    }
    printf("\n--- Deque recarregado ---\n");
    imprimir_deque(&dq);
    
    // Remoções por trás
    printf("\n--- Removendo por trás ---\n");
    while (remover_tras(&dq, &elemento)) {
        printf("Removido %d de trás\n", elemento);
        imprimir_deque(&dq);
    }
}

void testar_comportamento_circular() {
    printf("\n=== TESTE DO COMPORTAMENTO CIRCULAR ===\n");
    
    Deque dq;
    inicializar_deque(&dq);
    int i = 1;
    // Preenche parcialmente o deque
    for (i = 1; i <= 3; i++) {
        inserir_tras(&dq, i);
    }
    printf("Deque inicial: ");
    imprimir_deque_detalhado(&dq);
    
    // Simula operações que demonstram o comportamento circular
    int elemento;
    
    printf("\n--- Operações mistas ---\n");
    inserir_frente(&dq, 100);
    printf("Após inserir 100 na frente: ");
    imprimir_deque_detalhado(&dq);
    
    inserir_tras(&dq, 200);
    printf("Após inserir 200 atrás: ");
    imprimir_deque_detalhado(&dq);
    
    remover_frente(&dq, &elemento);
    printf("Após remover %d da frente: ", elemento);
    imprimir_deque_detalhado(&dq);
    
    remover_tras(&dq, &elemento);
    printf("Após remover %d de trás: ", elemento);
    imprimir_deque_detalhado(&dq);
}

void testar_capacidade_maxima() {
    printf("\n=== TESTE DE CAPACIDADE MÁXIMA ===\n");
    
    Deque dq;
    inicializar_deque(&dq);
    
    printf("Preenchendo deque até capacidade máxima...\n");
    int count = 0;
    while (!deque_cheio(&dq)) {
        if (count % 2 == 0) {
            inserir_frente(&dq, count);
        } else {
            inserir_tras(&dq, count);
        }
        count++;
    }
    
    printf("Deque cheio! Tamanho: %d\n", tamanho_deque(&dq));
    printf("Tentando inserir elemento adicional na frente: ");
    if (!inserir_frente(&dq, 999)) {
        printf("FALHOU (deque cheio)\n");
    }
    
    printf("Tentando inserir elemento adicional atrás: ");
    if (!inserir_tras(&dq, 999)) {
        printf("FALHOU (deque cheio)\n");
    }
}

void testar_deque_vazio() {
    printf("\n=== TESTE COM DEQUE VAZIO ===\n");
    
    Deque dq;
    inicializar_deque(&dq);
    
    int elemento;
    printf("Tentando remover da frente: ");
    if (!remover_frente(&dq, &elemento)) {
        printf("FALHOU (deque vazio)\n");
    }
    
    printf("Tentando remover de trás: ");
    if (!remover_tras(&dq, &elemento)) {
        printf("FALHOU (deque vazio)\n");
    }
    
    printf("Tentando consultar frente: ");
    if (!frente_deque(&dq, &elemento)) {
        printf("FALHOU (deque vazio)\n");
    }
    
    printf("Tentando consultar trás: ");
    if (!tras_deque(&dq, &elemento)) {
        printf("FALHOU (deque vazio)\n");
    }
}

void menu_interativo() {
    printf("\n=== MENU INTERATIVO - DEQUE ===\n");
    
    Deque dq;
    inicializar_deque(&dq);
    
    int opcao, elemento;
    
    do {
        printf("\n--- Operações ---\n");
        printf("1. Inserir na frente\n");
        printf("2. Inserir atrás\n");
        printf("3. Remover da frente\n");
        printf("4. Remover de trás\n");
        printf("5. Consultar frente\n");
        printf("6. Consultar trás\n");
        printf("7. Verificar se está vazio\n");
        printf("8. Verificar se está cheio\n");
        printf("9. Ver tamanho\n");
        printf("10. Imprimir deque\n");
        printf("11. Imprimir detalhado\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Elemento para inserir na frente: ");
                scanf("%d", &elemento);
                if (inserir_frente(&dq, elemento)) {
                    printf("Elemento %d inserido na frente!\n", elemento);
                } else {
                    printf("Erro: Deque cheio!\n");
                }
                break;
                
            case 2:
                printf("Elemento para inserir atrás: ");
                scanf("%d", &elemento);
                if (inserir_tras(&dq, elemento)) {
                    printf("Elemento %d inserido atrás!\n", elemento);
                } else {
                    printf("Erro: Deque cheio!\n");
                }
                break;
                
            case 3:
                if (remover_frente(&dq, &elemento)) {
                    printf("Elemento %d removido da frente!\n", elemento);
                } else {
                    printf("Erro: Deque vazio!\n");
                }
                break;
                
            case 4:
                if (remover_tras(&dq, &elemento)) {
                    printf("Elemento %d removido de trás!\n", elemento);
                } else {
                    printf("Erro: Deque vazio!\n");
                }
                break;
                
            case 5:
                if (frente_deque(&dq, &elemento)) {
                    printf("Elemento da frente: %d\n", elemento);
                } else {
                    printf("Deque vazio!\n");
                }
                break;
                
            case 6:
                if (tras_deque(&dq, &elemento)) {
                    printf("Elemento de trás: %d\n", elemento);
                } else {
                    printf("Deque vazio!\n");
                }
                break;
                
            case 7:
                printf("Deque está vazio? %s\n", deque_vazio(&dq) ? "Sim" : "Não");
                break;
                
            case 8:
                printf("Deque está cheio? %s\n", deque_cheio(&dq) ? "Sim" : "Não");
                break;
                
            case 9:
                printf("Tamanho do deque: %d\n", tamanho_deque(&dq));
                break;
                
            case 10:
                imprimir_deque(&dq);
                break;
                
            case 11:
                imprimir_deque_detalhado(&dq);
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
    printf("=== IMPLEMENTAÇÃO DE DEQUE ESTÁTICO ===\n\n");
    
    demonstrar_operacoes_basicas();
    testar_comportamento_circular();
    testar_capacidade_maxima();
    testar_deque_vazio();
    menu_interativo();
    
    return 0;
}
