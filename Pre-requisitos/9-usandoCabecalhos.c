#include "9-usandoCabecalhos.h"
#include <stdio.h>

// FunÃ§Ã£o para inicializar um Funcionario
void inicializarFuncionario(Funcionario *f, int id, const char *nome, float salario) {
    f->id = id;
    snprintf(f->nome, sizeof(f->nome), "%s", nome); 
	//A função snprintf() formata e armazena uma série de caracteres e valores na matriz buffer. 
	//Qualquer lista de argumentos é convertido e colocado de acordo com a especificação de formato correspondente no format-string.. 
	//A função snprintf() é idêntica à função sprintf() com a adição do argumento n , 
	//que indica o número máximo de caracteres (incluindo o caractere nulo final) a ser gravado no buffer..
    f->salario = salario;
}

// FunÃ§Ã£o para imprimir os dados de um Funcionario
void imprimirFuncionario(const Funcionario *f) {
    printf("ID: %d\n", f->id);
    printf("Nome: %s\n", f->nome);
    printf("Salario: %.2f\n", f->salario);
}

// FunÃ§Ã£o para atualizar o salÃ¡rio de um Funcionario
void atualizarSalario(Funcionario *f, float novoSalario) {
    f->salario = novoSalario;
}

