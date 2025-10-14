#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE 10000
#define MAX_STR 100

// Estrutura da fila
typedef struct {
    char dados[MAX_QUEUE][MAX_STR];
    int frente;
    int tras;
    int tamanho;
} Fila;

// Funções da fila
void inicializar_fila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

int fila_vazia(Fila *f) {
    return f->tamanho == 0;
}

int fila_cheia(Fila *f) {
    return f->tamanho == MAX_QUEUE;
}

int enfileirar(Fila *f, const char *str) {
    if (fila_cheia(f)) {
        return 0; // Falha - fila cheia
    }
    
    f->tras = (f->tras + 1) % MAX_QUEUE;
    strcpy(f->dados[f->tras], str);
    f->tamanho++;
    return 1; // Sucesso
}

int desenfileirar(Fila *f, char *str) {
    if (fila_vazia(f)) {
        return 0; // Falha - fila vazia
    }
    
    strcpy(str, f->dados[f->frente]);
    f->frente = (f->frente + 1) % MAX_QUEUE;
    f->tamanho--;
    return 1; // Sucesso
}

// Função principal que gera números binários usando fila
//Como Funciona:
//O algoritmo gera números binários em ordem de magnitude crescente:

//Começa: ["1"]

//Passo 1: Remove "1", imprime, adiciona "10" e "11" ? ["10", "11"]

//Passo 2: Remove "10", imprime, adiciona "100" e "101" ? ["11", "100", "101"]

//Passo 3: Remove "11", imprime, adiciona "110" e "111" ? ["100", "101", "110", "111"]
void binarios_n(int N) {
    if (N <= 0) {
        printf("N deve ser um numero positivo.\n");
        return;
    }
    
    Fila Q;
    inicializar_fila(&Q);
    
    printf("=== GERANDO NUMEROS BINARIOS DE 1 A %d ===\n", N);
    
    // Inicia com "1" na fila
    enfileirar(&Q, "1");
    
    int n = N;
    
    while (n > 0) {
        char s[MAX_STR];
        
        // Remove da fila
        desenfileirar(&Q, s);
        
        // Imprime o número binário
        printf("%s\n", s);
        
        // Gera os próximos números binários
        char s0[MAX_STR], s1[MAX_STR];
        
        // s + "0"
        strcpy(s0, s);
        strcat(s0, "0");
        
        // s + "1"  
        strcpy(s1, s);
        strcat(s1, "1");
        
        // Adiciona na fila
        enfileirar(&Q, s0);
        enfileirar(&Q, s1);
        
        n--;
    }
}

// Versão que mostra o processo passo a passo
void binarios_n_detalhado(int N) {
    if (N <= 0) {
        printf("N deve ser um numero positivo.\n");
        return;
    }
    
    Fila Q;
    inicializar_fila(&Q);
    
    printf("=== PROCESSO DETALHADO - BINARIOS DE 1 A %d ===\n", N);
    
    // Inicia com "1" na fila
    enfileirar(&Q, "1");
    printf("Inicializado: enfileirar(Q, \"1\")\n");
    
    int n = N;
    int passo = 1;
    
    while (n > 0) {
        char s[MAX_STR];
        
        // Remove da fila
        desenfileirar(&Q, s);
        
        printf("\n--- Passo %d ---\n", passo);
        printf("desenfileirar(Q) = %s\n", s);
        printf("Imprimir: %s\n", s);
        
        // Gera os próximos números binários
        char s0[MAX_STR], s1[MAX_STR];
        
        strcpy(s0, s);
        strcat(s0, "0");
        
        strcpy(s1, s);
        strcat(s1, "1");
        
        // Adiciona na fila
        enfileirar(&Q, s0);
        enfileirar(&Q, s1);
        
        printf("enfileirar(Q, \"%s\")\n", s0);
        printf("enfileirar(Q, \"%s\")\n", s1);
        
        n--;
        passo++;
    }
}

// Função para verificar se a saída está correta
void verificar_corretude(int N) {
    printf("\n=== VERIFICAÇÃO DA CORRETUDE ===\n");
    printf("Comparacao entre metodo com fila e calculo direto:\n\n");
    
    Fila Q;
    inicializar_fila(&Q);
    
    enfileirar(&Q, "1");
    int n = N;
    
    printf("%-10s | %-15s | %-15s\n", "Decimal", "Fila", "Calculo Direto");
    printf("-----------|-----------------|-----------------\n");
    
    int count = 1;
    while (n > 0) {
        char s[MAX_STR];
        desenfileirar(&Q, s);
        
        // Cálculo direto para verificação
        int decimal = count;
        char binario_direto[32] = "";
        int temp = decimal;
        int index = 0;
        
        // Converte para binário (gera na ordem inversa)
        while (temp > 0) {
            binario_direto[index++] = (temp % 2) ? '1' : '0';
            temp /= 2;
        }
        binario_direto[index] = '\0';
        
        // Inverte a string
        int j = 0;
        for (j = 0; j < index / 2; j++) {
            char temp_char = binario_direto[j];
            binario_direto[j] = binario_direto[index - 1 - j];
            binario_direto[index - 1 - j] = temp_char;
        }
        
        // Se a string estiver vazia (para 0), usa "0"
        if (strlen(binario_direto) == 0) {
            strcpy(binario_direto, "0");
        }
        
        printf("%-10d | %-15s | %-15s", count, s, binario_direto);
        
        // Verifica se são iguais
        if (strcmp(s, binario_direto) == 0) {
            printf(" CORRETO\n");
        } else {
            printf(" ERRADO\n");
        }
        
        // Gera próximos números
        char s0[MAX_STR], s1[MAX_STR];
        strcpy(s0, s);
        strcat(s0, "0");
        strcpy(s1, s);
        strcat(s1, "1");
        
        enfileirar(&Q, s0);
        enfileirar(&Q, s1);
        
        n--;
        count++;
    }
}

// Menu interativo
int main() {
    int opcao, N;
    
    printf("=== GERADOR DE NUMEROS BINARIOS USANDO FILAS ===\n\n");
    
    do {
        printf("Escolha uma opcao:\n");
        printf("1. Gerar binarios (modo simples)\n");
        printf("2. Gerar binarios (modo detalhado)\n");
        printf("3. Verificar corretude\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o valor de N: ");
                scanf("%d", &N);
                binarios_n(N);
                break;
                
            case 2:
                printf("Digite o valor de N: ");
                scanf("%d", &N);
                binarios_n_detalhado(N);
                break;
                
            case 3:
                printf("Digite o valor de N: ");
                scanf("%d", &N);
                verificar_corretude(N);
                break;
                
            case 4:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
        printf("\n");
    } while (opcao != 4);
    
    return 0;
}
