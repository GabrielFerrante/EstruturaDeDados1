#include <stdio.h>
#include "doubly_linked_list.c"

int main() {
    DoublyLinkedList dl;
    init(&dl);

    // Testando adição no início
    add_head(&dl, 30);
    add_head(&dl, 20);
    add_head(&dl, 10);
    
    printf("Apos adicionar 30, 20, 10 no inicio:\n");
    display_forward(&dl);
    display_backward(&dl);
    printf("\n");

    // Testando adição no final
    add_tail(&dl, 40);
    add_tail(&dl, 50);
    
    printf("Apos adicionar 40, 50 no final:\n");
    display_forward(&dl);
    display_backward(&dl);
    printf("\n");

    // Testando remoção do meio
    printf("Removendo 30: %s\n", remove_node(&dl, 30) ? "Sucesso" : "Falha");
    display_forward(&dl);
    display_backward(&dl);
    printf("\n");

    // Testando remoção do início
    printf("Removendo 10: %s\n", remove_node(&dl, 10) ? "Sucesso" : "Falha");
    display_forward(&dl);
    display_backward(&dl);
    printf("\n");

    // Testando remoção do final
    printf("Removendo 50: %s\n", remove_node(&dl, 50) ? "Sucesso" : "Falha");
    display_forward(&dl);
    display_backward(&dl);
    printf("\n");

    // Testando remoção de elemento inexistente
    printf("Removendo 100: %s\n", remove_node(&dl, 100) ? "Sucesso" : "Falha");
    display_forward(&dl);
    display_backward(&dl);

    free_list(&dl);
    return 0;
}
