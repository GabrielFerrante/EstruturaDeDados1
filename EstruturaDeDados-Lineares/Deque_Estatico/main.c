#include <stdio.h>
#include "deque_estatico.c"
#include <locale.h>

void demonstrar_operacoes_basicas() {
    printf("=== OPERA��ES B�SICAS DO DEQUE ===\n");
    
    Deque dq;
    inicializar_deque(&dq);
    
    printf("Deque inicializado:\n");
    imprimir_deque_detalhado(&dq);
    
    // Inser��es pela frente
    printf("\n--- Inserindo pela frente ---\n");
    int i = 1;
    for (i = 1; i <= 3; i++) {
        if (inserir_frente(&dq, i * 10)) {
            printf("Inserido %d pela frente\n", i * 10);
            imprimir_deque(&dq);
        }
    }
    
    // Inser��es por tr�s
    printf("\n--- Inserindo por tr�s ---\n");
    i = 4;
    for (i = 4; i <= 6; i++) {
        if (inserir_tras(&dq, i * 10)) {
            printf("Inserido %d por tr�s\n", i * 10);
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
        printf("Elemento de tr�s: %d\n", elemento);
    }
    
    // Remo��es pela frente
    printf("\n--- Removendo pela frente ---\n");
    while (remover_frente(&dq, &elemento)) {
        printf("Removido %d da frente\n", elemento);
        imprimir_deque(&dq);
    }
    
    // Reinicializar para demonstrar remo��o por tr�s
    inicializar_deque(&dq);
	i = 1;
    for (i = 1; i <= 3; i++) {
        inserir_tras(&dq, i * 10);
    }
    printf("\n--- Deque recarregado ---\n");
    imprimir_deque(&dq);
    
    // Remo��es por tr�s
    printf("\n--- Removendo por tr�s ---\n");
    while (remover_tras(&dq, &elemento)) {
        printf("Removido %d de tr�s\n", elemento);
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
    
    // Simula opera��es que demonstram o comportamento circular
    int elemento;
    
    printf("\n--- Opera��es mistas ---\n");
    inserir_frente(&dq, 100);
    printf("Ap�s inserir 100 na frente: ");
    imprimir_deque_detalhado(&dq);
    
    inserir_tras(&dq, 200);
    printf("Ap�s inserir 200 atr�s: ");
    imprimir_deque_detalhado(&dq);
    
    remover_frente(&dq, &elemento);
    printf("Ap�s remover %d da frente: ", elemento);
    imprimir_deque_detalhado(&dq);
    
    remover_tras(&dq, &elemento);
    printf("Ap�s remover %d de tr�s: ", elemento);
    imprimir_deque_detalhado(&dq);
}

void testar_capacidade_maxima() {
    printf("\n=== TESTE DE CAPACIDADE M�XIMA ===\n");
    
    Deque dq;
    inicializar_deque(&dq);
    
    printf("Preenchendo deque at� capacidade m�xima...\n");
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
    
    printf("Tentando inserir elemento adicional atr�s: ");
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
    
    printf("Tentando remover de tr�s: ");
    if (!remover_tras(&dq, &elemento)) {
        printf("FALHOU (deque vazio)\n");
    }
    
    printf("Tentando consultar frente: ");
    if (!frente_deque(&dq, &elemento)) {
        printf("FALHOU (deque vazio)\n");
    }
    
    printf("Tentando consultar tr�s: ");
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
        printf("\n--- Opera��es ---\n");
        printf("1. Inserir na frente\n");
        printf("2. Inserir atr�s\n");
        printf("3. Remover da frente\n");
        printf("4. Remover de tr�s\n");
        printf("5. Consultar frente\n");
        printf("6. Consultar tr�s\n");
        printf("7. Verificar se est� vazio\n");
        printf("8. Verificar se est� cheio\n");
        printf("9. Ver tamanho\n");
        printf("10. Imprimir deque\n");
        printf("11. Imprimir detalhado\n");
        printf("0. Sair\n");
        printf("Op��o: ");
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
                printf("Elemento para inserir atr�s: ");
                scanf("%d", &elemento);
                if (inserir_tras(&dq, elemento)) {
                    printf("Elemento %d inserido atr�s!\n", elemento);
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
                    printf("Elemento %d removido de tr�s!\n", elemento);
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
                    printf("Elemento de tr�s: %d\n", elemento);
                } else {
                    printf("Deque vazio!\n");
                }
                break;
                
            case 7:
                printf("Deque est� vazio? %s\n", deque_vazio(&dq) ? "Sim" : "N�o");
                break;
                
            case 8:
                printf("Deque est� cheio? %s\n", deque_cheio(&dq) ? "Sim" : "N�o");
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
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 0);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    printf("=== IMPLEMENTA��O DE DEQUE EST�TICO ===\n\n");
    
    demonstrar_operacoes_basicas();
    testar_comportamento_circular();
    testar_capacidade_maxima();
    testar_deque_vazio();
    menu_interativo();
    
    return 0;
}
