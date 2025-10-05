#include <stdio.h>
#include <stdlib.h>

// Funcao que verifica se a pessoa i conhece a pessoa j
int conhece(int i, int j, int **M) {
    return M[i][j];
}

// Funcao que encontra a celebridade, se existir
int celebridade(int **M, int n) {
    // Aloca arrays para indegree e outdegree
    int *indegree = (int*)calloc(n, sizeof(int)); //Inicializa automaticamente toda a memoria alocada com zeros (observação, no malloc não inicializa)
    int *outdegree = (int*)calloc(n, sizeof(int));
    
    if (indegree == NULL || outdegree == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return -1;
    }
    
    // Calcula indegree e outdegree para cada pessoa
    int i = 0;
    for (i = 0; i < n; i++) {
        int j = 0;
        for (j = 0; j < n; j++) {
            int x = conhece(i, j, M);
            indegree[j] += x;
            outdegree[i] += x;
        }
    }
    
    // Procura por uma celebridade
    i=0;
    for (i = 0; i < n; i++) {
        if (indegree[i] == n - 1 && outdegree[i] == 0) {
            free(indegree);
            free(outdegree);
            return i; // Encontrou a celebridade
        }
    }
    
    free(indegree);
    free(outdegree);
    return -1; // Nao existe celebridade
}

// Funcao para criar e inicializar uma matriz n x n
int** criar_matriz(int n) {
    int **M = (int**)malloc(n * sizeof(int*));
    int i = 0;
    for (i = 0; i < n; i++) {
        M[i] = (int*)malloc(n * sizeof(int));
    }
    return M;
}

// Funcao para liberar a memoria da matriz
void liberar_matriz(int **M, int n) {
	int i = 0;
    for (i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);
}

// Funcao para imprimir a matriz de relacoes
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
        for ( j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("PROBLEMA DA CELEBRIDADE\n\n");
    
    // Teste 1: Caso com celebridade (pessoa 2)
    printf("--- Teste 1: Com celebridade ---\n");
    int n1 = 4;
    int **M1 = criar_matriz(n1);
    
    // Inicializa a matriz para o teste 1
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
    int celeb1 = celebridade(M1, n1);
    if (celeb1 != -1) {
        printf("Celebridade encontrada: Pessoa %d\n", celeb1);
    } else {
        printf("Nao existe celebridade\n");
    }
    liberar_matriz(M1, n1);
    
    // Teste 2: Caso sem celebridade
    printf("\nTeste 2: Sem celebridade\n");
    int n2 = 3;
    int **M2 = criar_matriz(n2);
    
    int teste2[3][3] = {
        {0, 1, 1},
        {1, 0, 1},
        {0, 1, 0}
    };
    i = 0;
    for (i = 0; i < n2; i++) {
    	int j = 0;
        for (j = 0; j < n2; j++) {
            M2[i][j] = teste2[i][j];
        }
    }
    
    imprimir_matriz(M2, n2);
    int celeb2 = celebridade(M2, n2);
    if (celeb2 != -1) {
        printf("Celebridade encontrada: Pessoa %d\n", celeb2);
    } else {
        printf("Nao existe celebridade\n");
    }
    liberar_matriz(M2, n2);
    
    // Teste 3: Caso onde todos se conhecem
    printf("\nTeste 3: Todos se conhecem\n");
    int n3 = 3;
    int **M3 = criar_matriz(n3);
    
    int teste3[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    i = 0;
    for (i = 0; i < n3; i++) {
    	int j = 0;
        for (j = 0; j < n3; j++) {
            M3[i][j] = teste3[i][j];
        }
    }
    
    imprimir_matriz(M3, n3);
    int celeb3 = celebridade(M3, n3);
    if (celeb3 != -1) {
        printf("Celebridade encontrada: Pessoa %d\n", celeb3);
    } else {
        printf("Nao existe celebridade\n");
    }
    liberar_matriz(M3, n3);
    
    // Teste 4: Caso com auto-conhecimento (diagonal = 1)
    printf("\nTeste 4: Com auto-conhecimento\n");
    int n4 = 3;
    int **M4 = criar_matriz(n4);
    
    int teste4[3][3] = {
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 1}
    };
    i = 0;
    for (i = 0; i < n4; i++) {
    	int j = 0;
        for (j = 0; j < n4; j++) {
            M4[i][j] = teste4[i][j];
        }
    }
    
    imprimir_matriz(M4, n4);
    int celeb4 = celebridade(M4, n4);
    if (celeb4 != -1) {
        printf("Celebridade encontrada: Pessoa %d\n", celeb4);
    } else {
        printf("Nao existe celebridade\n");
    }
    liberar_matriz(M4, n4);
    
    return 0;
}
