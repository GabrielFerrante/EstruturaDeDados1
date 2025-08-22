#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main() {
	setlocale(LC_ALL, "");
    FILE *fp;
    char buffer[100];

    // 1. Criação e escrita em arquivo
    fp = fopen("exemplo.txt", "w");
    if (fp == NULL) {
        perror("Erro ao criar arquivo");
        return 1;
    }
    fprintf(fp, "Linha 1\nLinha 2\n");
    fclose(fp);

    // 2. Leitura de arquivo
    fp = fopen("exemplo.txt", "r");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo para leitura");
        return 1;
    }
    printf("Conte�do do arquivo:\n");
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    fclose(fp);

    // 3. Atualização (adição de conteúdo)
    fp = fopen("exemplo.txt", "a");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo para atualização");
        return 1;
    }
    fprintf(fp, "Linha 3 adicionada\n");
    fclose(fp);

    // 4. Remoção de arquivo
    if (remove("exemplo.txt") == 0) {
        printf("\nArquivo removido com sucesso.\n");
    } else {
        perror("Erro ao remover arquivo");
    }

    return 0;
}
