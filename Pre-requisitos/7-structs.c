#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
// Definição de uma struct para representar uma pessoa
struct Pessoa {
    char nome[50];
    int idade;
};

// Função para exibir os dados de uma pessoa
void exibirPessoa(struct Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
}

int main() {
	setlocale(LC_ALL, "");
    // Criação e inicialização de uma struct
    struct Pessoa pessoa1;
    strcpy(pessoa1.nome, "Jo�o");
    pessoa1.idade = 25;

    // Chamada da função passando a struct como argumento
    exibirPessoa(pessoa1);

    // Outra forma de inicializar uma struct
    struct Pessoa pessoa2 = {"Maria", 30};
    exibirPessoa(pessoa2);

    return 0;
}
