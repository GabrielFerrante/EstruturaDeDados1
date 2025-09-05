#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char dir[] = "BEDC";
const int dr[] = {1, 0, 0, -1};
const int dc[] = {0, -1, 1, 0};


//CODIGOS REFERENTES A CONSTRUÇÕES DE LISTAS, CONTEÚDO AVANÇADO
typedef struct {
    char** caminhos;
    int quantidade; //Quantidade de caminhos
    int capacidade; //Capacidade 
} ListaCaminhos;

bool ehValido(int linha, int coluna, int n, int labirinto[4][4], bool visitado[4][4]) {
    return linha >= 0 && coluna >= 0 && linha < n && coluna < n && 
           labirinto[linha][coluna] == 1 && !visitado[linha][coluna];
}

void inicializarLista(ListaCaminhos* lista, int capacidade) {
    lista->caminhos = malloc(capacidade * sizeof(char*));
    lista->quantidade = 0;
    lista->capacidade = capacidade;
}

void adicionarCaminho(ListaCaminhos* lista, const char* caminho) {
    if (lista->quantidade >= lista->capacidade) {
        lista->capacidade *= 2;
        lista->caminhos = realloc(lista->caminhos, lista->capacidade * sizeof(char*));
    }
    lista->caminhos[lista->quantidade] = malloc(strlen(caminho) + 1);
    strcpy(lista->caminhos[lista->quantidade], caminho);
    lista->quantidade++;
}

void liberarLista(ListaCaminhos* lista) {
	int i = 0;
    for(i=0; i < lista->quantidade; i++) {
        free(lista->caminhos[i]);
    }
    free(lista->caminhos);

}




void encontrarCaminhos(int linha, int coluna, int n, int labirinto[4][4], bool visitado[4][4],
                      char* caminhoAtual, int indiceCaminho, ListaCaminhos* resultados) {
    
    if (linha == n - 1 && coluna == n - 1) {
        caminhoAtual[indiceCaminho] = '\0';
        adicionarCaminho(resultados, caminhoAtual);
        return;
    }
    
    visitado[linha][coluna] = true;
    int i = 0;
    for (i = 0; i < 4; i++) {
        int novaLinha = linha + dr[i];
        int novaColuna = coluna + dc[i];
        
        if (ehValido(novaLinha, novaColuna, n, labirinto, visitado)) {
            caminhoAtual[indiceCaminho] = dir[i];
            encontrarCaminhos(novaLinha, novaColuna, n, labirinto, visitado, 
                             caminhoAtual, indiceCaminho + 1, resultados);
        }
    }
    
    visitado[linha][coluna] = false;
}

ListaCaminhos ratoNoLabirinto(int labirinto[4][4]) {
    ListaCaminhos resultados;
    inicializarLista(&resultados, 10);
    int n = 4; // TAMANHO DE LINHAS E COLUANS
    
    if (labirinto[0][0] == 1 && labirinto[n-1][n-1] == 1) {
        bool visitado[4][4] = {false};
        char* caminhoAtual = malloc(n * n * sizeof(char));
        encontrarCaminhos(0, 0, n, labirinto, visitado, caminhoAtual, 0, &resultados);
        free(caminhoAtual);
    }
    
    return resultados;
}

int main() {
    int labirinto[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {0, 1, 1, 1}
    }; //Lembrando, ele não anda nas diagonais.
    
    ListaCaminhos resultados = ratoNoLabirinto(labirinto);
    
    if (resultados.quantidade == 0) {
        printf("-1\n");
    } else {
    	int i = 0;
        for ( i = 0; i < resultados.quantidade; i++) {
            printf("Caminho opcao %d: %s\n",i, resultados.caminhos[i]);
        }
    }
    
    liberarLista(&resultados);
    return 0;
}
