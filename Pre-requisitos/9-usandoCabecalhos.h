#ifndef FUNCIONARIO_H  //Código de inclusão para evitar múltiplas inclusões
#define FUNCIONARIO_H

typedef struct {
    int id;
    char nome[50];
    float salario;
} Funcionario;

void inicializarFuncionario(Funcionario *f, int id, const char *nome, float salario);
void imprimirFuncionario(const Funcionario *f);
void atualizarSalario(Funcionario *f, float novoSalario);

#endif

