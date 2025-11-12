#include <stdio.h>
#include "lista_ordenada.c"

int main() {
    ListaOrdenada lista;
    inicializar(&lista);

    // Inserindo elementos
    insert(&lista, 30);
    insert(&lista, 10);
    insert(&lista, 20);
    insert(&lista, 40);
    insert(&lista, 5);

    printf("Lista inicial: ");
    imprimir(&lista); // 5 10 20 30 40

    // Testando remoção do meio
    if (remove_node(&lista, 20)) {
        printf("Chave 20 removida com sucesso!\n");
    } else {
        printf("Chave 20 nao encontrada para remoção!\n");
    }
    printf("Lista apos remover 20: ");
    imprimir(&lista); // 5 10 30 40

    // Testando remoção do início
    if (remove_node(&lista, 5)) {
        printf("Chave 5 removida com sucesso!\n");
    } else {
        printf("Chave 5 nao encontrada para remoção!\n");
    }
    printf("Lista apos remover 5: ");
    imprimir(&lista); // 10 30 40

    // Testando remoção do fim
    if (remove_node(&lista, 40)) {
        printf("Chave 40 removida com sucesso!\n");
    } else {
        printf("Chave 40 nao encontrada para remoção!\n");
    }
    printf("Lista apos remover 40: ");
    imprimir(&lista); // 10 30

    // Testando remoção de chave inexistente
    if (remove_node(&lista, 25)) {
        printf("Chave 25 removida com sucesso!\n");
    } else {
        printf("Chave 25 nao encontrada para remoção!\n");
    }
    printf("Lista apos tentar remover 25: ");
    imprimir(&lista); // 10 30

    liberar(&lista);
    return 0;
}
