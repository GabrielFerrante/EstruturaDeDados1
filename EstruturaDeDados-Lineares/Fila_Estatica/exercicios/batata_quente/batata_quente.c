#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.c"
#include "batata_quente.h"

char* batata_quente(char **nomes, int K, int Max) {
    Fila Q;
    inicializar(&Q);
    
    printf("=== INÍCIO DO JOGO DA BATATA QUENTE ===\n");
    printf("Crianças participantes: ");
    int i;
    for (i = 0; i < K; i++) {
        printf("%s ", nomes[i]);
    }
    printf("\n");
    printf("Número máximo de passes: %d\n\n", Max);
    
    // Enfileira todas as crianças (seus índices)
    for (i = 0; i < K; i++) {
        if (!enfileirar(&Q, i)) {
            printf("Erro ao enfileirar criança %d\n", i);
            return NULL;
        }
    }
    
    int rodada = 1;
    
    while (tamanho(&Q) > 1) {
        printf("--- Rodada %d ---\n", rodada);
        printf("Crianças restantes: ");
        
        // Mostra as crianças restantes
        int temp_frente = Q.frente;
        for (i = 0; i < Q.tamanho; i++) {
            int idx = Q.dados[temp_frente];
            printf("%s ", nomes[idx]);
            temp_frente = (temp_frente + 1) % MAX;
        }
        printf("\n");
        
        // Simula os passes da batata
        int passes = rand() % Max + 1;
        printf("Batata será passada %d vezes\n", passes);
        
        // Inicializa a variável que rastreia quem tem a batata
        int crianca_com_batata = -1; // Inicializada com valor inválido
        
        // Obter a criança que começa com a batata
        if (!frente(&Q, &crianca_com_batata)) {
            printf("Erro: não foi possível obter a frente da fila\n");
            return NULL;
        }
        
        printf("Batata começa com: %s\n", nomes[crianca_com_batata]);
        
        // Realiza os passes (n-1 passes normais)
        for (i = 1; i < passes; i++) {
            int crianca_atual = -1; // Inicializada
            
            // Remove a criança da frente e coloca no final
            if (!desenfileirar(&Q, &crianca_atual)) {
                printf("Erro ao desenfileirar\n");
                return NULL;
            }
            
            if (!enfileirar(&Q, crianca_atual)) {
                printf("Erro ao enfileirar\n");
                return NULL;
            }
            
            // Mostra para quem a batata está sendo passada
            int proxima_crianca = -1;
            if (!frente(&Q, &proxima_crianca)) {
                printf("Erro ao ver a frente da fila\n");
                return NULL;
            }
            
            printf("  Passa %d: %s passa para %s\n", 
                   i, nomes[crianca_atual], nomes[proxima_crianca]);
        }
        
        // Último passe - a criança que está com a batata é eliminada
        int eliminado = -1; // Inicializada
        if (!desenfileirar(&Q, &eliminado)) {
            printf("Erro ao eliminar criança\n");
            return NULL;
        }
        
        printf("  Último passe: %s fica com a batata! \n", nomes[eliminado]);
        printf("  ELIMINADO: %s\n\n", nomes[eliminado]);
        
        rodada++;
    }
    
    // A última criança restante é a vencedora
    int vencedor_idx = -1; // Inicializada
    if (!desenfileirar(&Q, &vencedor_idx)) {
        printf("Erro ao obter vencedor\n");
        return NULL;
    }
    
    printf("=== FIM DO JOGO ===\n");
    printf(" VENCEDOR: %s \n", nomes[vencedor_idx]);
    
    return nomes[vencedor_idx];
}
