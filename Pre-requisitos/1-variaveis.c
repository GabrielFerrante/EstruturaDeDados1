#include <stdio.h>
#include <locale.h>

// Este programa demonstra os tipos de variáveis fundamentais em C

int main() {
	setlocale(LC_ALL, "");
    // Declaração de uma variável do tipo inteiro
    int idade = 25; // armazena números inteiros

    // Declaração de uma variável do tipo ponto flutuante
    float altura = 1.75f; // armazena números decimais de precisão simples

    // Declaração de uma variável do tipo double
    double peso = 70.5; // armazena números decimais de precisão dupla

    // Declaração de uma variável do tipo caractere
    char inicial = 'A'; // armazena um único caractere

    // Exibe os valores das variáveis na tela
    printf("Idade: %d\n", idade);        // %d para inteiros
    printf("Altura: %.2f\n", altura);    // %.2f para float com 2 casas decimais
    printf("Peso: %.1lf\n", peso);       // %.1lf para double com 1 casa decimal
    printf("Inicial: %c\n", inicial);    // %c para caractere

    // Entrada de dados do usuário
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);

    printf("Digite seu peso (em kg): ");
    scanf("%lf", &peso);

    printf("Digite a inicial do seu nome: ");
    // O espaço antes do %c ignora caracteres de nova linha deixados no buffer
    scanf(" %c", &inicial);

    // Exibe os valores informados pelo usuário
    printf("\nValores informados:\n");
    printf("Idade: %d\n", idade);
    printf("Altura: %.2f\n", altura);
    printf("Peso: %.1lf\n", peso);
    printf("Inicial: %c\n", inicial);
    
    system("PAUSE");
    return 0; // Indica que o programa terminou com sucesso
}
