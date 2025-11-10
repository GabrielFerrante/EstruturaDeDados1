#include <stdio.h>
#include "fila_dinamica.c"

int main() {
    FilaDinamica fila;
    inicializar(&fila);

    // Enfileirando valores
    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);

    // Desenfileirando e exibindo (deve sair na mesma ordem: 10, 20, 30)
    printf("%d ", desenfileirar(&fila));
    printf("%d ", desenfileirar(&fila));
    printf("%d ", desenfileirar(&fila));
    printf("%d ", desenfileirar(&fila)); // Tentativa extra

    return 0;
}
