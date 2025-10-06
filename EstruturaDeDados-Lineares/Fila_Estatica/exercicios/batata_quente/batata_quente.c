#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.c"
#include "batata_quente.h"

char* batata_quente(char **nomes, int K, int Max) {
    Fila Q;
    inicializar(&Q);
    
    printf("=== IN�CIO DO JOGO DA BATATA QUENTE ===\n");
    printf("Crian�as participantes: ");
    int i;
    for (i = 0; i < K; i++) {
        printf("%s ", nomes[i]);
    }
    printf("\n");
    printf("N�mero m�ximo de passes: %d\n\n", Max);
    
    // Enfileira todas as crian�as (seus �ndices)
    for (i = 0; i < K; i++) {
        if (!enfileirar(&Q, i)) {
            printf("Erro ao enfileirar crian�a %d\n", i);
            return NULL;
        }
    }
    
    int rodada = 1;
    
    while (tamanho(&Q) > 1) {
        printf("--- Rodada %d ---\n", rodada);
        printf("Crian�as restantes: ");
        
        // Mostra as crian�as restantes
        int temp_frente = Q.frente;
        for (i = 0; i < Q.tamanho; i++) {
            int idx = Q.dados[temp_frente];
            printf("%s ", nomes[idx]);
            temp_frente = (temp_frente + 1) % MAX;
        }
        printf("\n");
        
        // Simula os passes da batata
        int passes = rand() % Max + 1;
        printf("Batata ser� passada %d vezes\n", passes);
        
        // Inicializa a vari�vel que rastreia quem tem a batata
        int crianca_com_batata = -1; // Inicializada com valor inv�lido
        
        // Obter a crian�a que come�a com a batata
        if (!frente(&Q, &crianca_com_batata)) {
            printf("Erro: n�o foi poss�vel obter a frente da fila\n");
            return NULL;
        }
        
        printf("Batata come�a com: %s\n", nomes[crianca_com_batata]);
        
        // Realiza os passes (n-1 passes normais)
        for (i = 1; i < passes; i++) {
            int crianca_atual = -1; // Inicializada
            
            // Remove a crian�a da frente e coloca no final
            if (!desenfileirar(&Q, &crianca_atual)) {
                printf("Erro ao desenfileirar\n");
                return NULL;
            }
            
            if (!enfileirar(&Q, crianca_atual)) {
                printf("Erro ao enfileirar\n");
                return NULL;
            }
            
            // Mostra para quem a batata est� sendo passada
            int proxima_crianca = -1;
            if (!frente(&Q, &proxima_crianca)) {
                printf("Erro ao ver a frente da fila\n");
                return NULL;
            }
            
            printf("  Passa %d: %s passa para %s\n", 
                   i, nomes[crianca_atual], nomes[proxima_crianca]);
        }
        
        // �ltimo passe - a crian�a que est� com a batata � eliminada
        int eliminado = -1; // Inicializada
        if (!desenfileirar(&Q, &eliminado)) {
            printf("Erro ao eliminar crian�a\n");
            return NULL;
        }
        
        printf("  �ltimo passe: %s fica com a batata! \n", nomes[eliminado]);
        printf("  ELIMINADO: %s\n\n", nomes[eliminado]);
        
        rodada++;
    }
    
    // A �ltima crian�a restante � a vencedora
    int vencedor_idx = -1; // Inicializada
    if (!desenfileirar(&Q, &vencedor_idx)) {
        printf("Erro ao obter vencedor\n");
        return NULL;
    }
    
    printf("=== FIM DO JOGO ===\n");
    printf(" VENCEDOR: %s \n", nomes[vencedor_idx]);
    
    return nomes[vencedor_idx];
}
