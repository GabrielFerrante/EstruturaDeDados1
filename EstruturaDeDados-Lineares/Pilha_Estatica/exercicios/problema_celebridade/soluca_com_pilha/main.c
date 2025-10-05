#include <stdio.h>
#include <stdlib.h>

// Definição da pilha estática
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

// Funções da pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

int empilhar(Pilha *p, int elemento) {
    if (p->topo == MAX - 1) {
        return 0; // Pilha cheia
    }
    p->dados[++p->topo] = elemento;
    return 1;
}

int desempilhar(Pilha *p, int *elemento) {
    if (p->topo == -1) {
        return 0; // Pilha vazia
    }
    *elemento = p->dados[p->topo--];
    return 1;
}

int tamanho_pilha(Pilha *p) {
    return p->topo + 1;
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

// Função que verifica se a pessoa i conhece a pessoa j
int conhece(int i, int j, int **M) {
    return M[i][j];
}

// Função principal que encontra a celebridade usando pilha
int celebridade_pilha(int **M, int n) {
    Pilha S;
    inicializar(&S);
    int C = -1; // Não há celebridade inicialmente
    
    // Empilha todas as pessoas (0 a n-1)
    int i = 0;
    for (i = 0; i < n; i++) {
        if (!empilhar(&S, i)) {
            printf("Erro: Pilha cheia!\n");
            return -1;
        }
    }
    
    // Eliminação até sobrar um candidato
    while (tamanho_pilha(&S) > 1) {
        int A, B;
        desempilhar(&S, &A);
        desempilhar(&S, &B);
        
        if (conhece(A, B, M)) {
            // A conhece B, então A não pode ser celebridade
            empilhar(&S, B);
        } else {
            // A não conhece B, então B não pode ser celebridade
            empilhar(&S, A);
        }
    }
    
    // O candidato restante é C
    desempilhar(&S, &C);
    
    // Verifica se C é realmente uma celebridade
    i = 0;
    for (i = 0; i < n; i++) {
        if (i != C && (conhece(C, i, M) || !conhece(i, C, M))) {
            return -1; // C não é celebridade
        }
    }
    
    return C; // C é a celebridade
}

// Funções auxiliares para matriz
int** criar_matriz(int n) {
    int **M = (int**)malloc(n * sizeof(int*));
    int i = 0;
    for (i = 0; i < n; i++) {
        M[i] = (int*)calloc(n, sizeof(int));
    }
    return M;
}

void liberar_matriz(int **M, int n) {
	int i = 0;
    for (i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);
}

void imprimir_matriz(int **M, int n) {
    printf("Matriz de relacoes:\n");
    printf("   ");
    int j = 0;
    for (j = 0; j < n; j++) {
        printf("%d ", j);
    }
    printf("\n");
    int i = 0;
    for (i = 0; i < n; i++) {
        printf("%d: ", i);
        int j = 0;
        for (j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("=== PROBLEMA DA CELEBRIDADE COM PILHA ===\n\n");
    
    // Teste 1: Caso com celebridade (pessoa 2)
    printf("--- Teste 1: Com celebridade ---\n");
    int n1 = 4;
    int **M1 = criar_matriz(n1);
    
    int teste1[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };
    int i = 0;
    for (i = 0; i < n1; i++) {
    	int j = 0;
        for (j = 0; j < n1; j++) {
            M1[i][j] = teste1[i][j];
        }
    }
    
    imprimir_matriz(M1, n1);
    int celeb1 = celebridade_pilha(M1, n1);
    if (celeb1 != -1) {
        printf("Celebridade encontrada: Pessoa %d\n", celeb1);
    } else {
        printf("Nao existe celebridade\n");
    }
    liberar_matriz(M1, n1);
    
    // Teste 2: Caso sem celebridade
    printf("\n--- Teste 2: Sem celebridade ---\n");
    int n2 = 3;
    int **M2 = criar_matriz(n2);
    
    int teste2[3][3] = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 0, 0}
    };
    i = 0;
    for (i = 0; i < n2; i++) {
    	int j = 0;
        for (j = 0; j < n2; j++) {
            M2[i][j] = teste2[i][j];
        }
    }
    
    imprimir_matriz(M2, n2);
    int celeb2 = celebridade_pilha(M2, n2);
    if (celeb2 != -1) {
        printf("Celebridade encontrada: Pessoa %d\n", celeb2);
    } else {
        printf("Nao existe celebridade\n");
    }
    liberar_matriz(M2, n2);
    
    // Teste 3: Versão passo a passo para entender o algoritmo
    printf("\n--- Teste 3: Demonstracao passo a passo ---\n");
    int n3 = 4;
    int **M3 = criar_matriz(n3);
    
    int teste3[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };
    i = 0;
    for (i = 0; i < n3; i++) {
    	int j = 0;
        for (j = 0; j < n3; j++) {
            M3[i][j] = teste3[i][j];
        }
    }
    
    imprimir_matriz(M3, n3);
    
    // Demonstração passo a passo
    printf("\nProcesso de eliminacao:\n");
    Pilha S;
    inicializar(&S);
    
    // Empilha todas as pessoas
    i = 0;
    for (i = 0; i < n3; i++) {
        empilhar(&S, i);
    }
    printf("Pilha inicial: [0, 1, 2, 3]\n");
    
    // Primeira eliminação: 3 vs 2
    int A, B;
    desempilhar(&S, &A); // A = 3
    desempilhar(&S, &B); // B = 2
    printf("Comparacao: conhece(%d, %d) = %d -> ", A, B, conhece(A, B, M3));
    if (conhece(A, B, M3)) {
        printf("3 conhece 2, elimina 3\n");
        empilhar(&S, B); // Empilha 2
    } else {
        printf("3 nao conhece 2, elimina 2\n");
        empilhar(&S, A); // Empilha 3
    }
    
    // Segunda eliminação: 2 vs 1
    desempilhar(&S, &A); // A = 2
    desempilhar(&S, &B); // B = 1
    printf("Comparacao: conhece(%d, %d) = %d -> ", A, B, conhece(A, B, M3));
    if (conhece(A, B, M3)) {
        printf("2 conhece 1, elimina 2\n");
        empilhar(&S, B); // Empilha 1
    } else {
        printf("2 nao conhece 1, elimina 1\n");
        empilhar(&S, A); // Empilha 2
    }
    
    // Terceira eliminação: 2 vs 0
    desempilhar(&S, &A); // A = 1
    desempilhar(&S, &B); // B = 0
    printf("Comparacao: conhece(%d, %d) = %d -> ", A, B, conhece(A, B, M3));
    if (conhece(A, B, M3)) {
        printf("2 conhece 0, elimina 1\n");
        empilhar(&S, B); // Empilha 0
    } else {
        printf("2 nao conhece 0, elimina 0\n");
        empilhar(&S, A); // Empilha 1
    }
    
    int candidato;
    desempilhar(&S, &candidato);
    printf("Candidato final: %d\n", candidato);
    
    // Verificação final
    printf("Verificando candidato %d:\n", candidato);
    int eh_celebridade = 1;
    for (i = 0; i < n3; i++) {
        if (i != candidato) {
            if (conhece(candidato, i, M3)) {
                printf("  conhece(%d, %d) = 1 : C conhece alguem! \n", candidato, i);
                eh_celebridade = 0;
            } else if (!conhece(i, candidato, M3)) {
                printf("  conhece(%d, %d) = 0 : Alguém nao conhece C! \n", i, candidato);
                eh_celebridade = 0;
            } else {
                printf("  conhece(%d, %d) = 0 :, conhece(%d, %d) = 1 \n", 
                       candidato, i, i, candidato);
            }
        }
    }
    
    if (eh_celebridade) {
        printf("Candidato %d e a celebridade! \n", candidato);
    } else {
        printf("Candidato %d nao e celebridade! \n", candidato);
    }
    
    liberar_matriz(M3, n3);
    
    return 0;
}
