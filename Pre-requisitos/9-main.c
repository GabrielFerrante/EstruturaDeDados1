#include "9-usandoCabecalhos.c"
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    Funcionario f1;
    inicializarFuncionario(&f1, 1, "Carlos Silva", 3500.50);
    imprimirFuncionario(&f1); 
    atualizarSalario(&f1, 4000.00);
    imprimirFuncionario(&f1);
    return 0;
}
