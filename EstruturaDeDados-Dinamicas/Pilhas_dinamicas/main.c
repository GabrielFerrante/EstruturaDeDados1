#include <stdio.h>
#include "pilha_dinamica.c"

int main() {
    PilhaDinamica pilha;
    inicializar(&pilha);

    // Empilhando valores
    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);

    // Desempilhando e exibindo
    printf("%d ", desempilhar(&pilha));
    printf("%d ", desempilhar(&pilha));
    printf("%d ", desempilhar(&pilha));
    printf("%d ", desempilhar(&pilha)); // Tentativa extra

    return 0;
}
