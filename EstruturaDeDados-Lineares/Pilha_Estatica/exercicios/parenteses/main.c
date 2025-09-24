#include <stdio.h>
#include <string.h>
#include "verificador.c"
#include <locale.h>

void testar_expressao(char *expressao) {
    printf("Expressão: %s\n", expressao);
    
    if (verificar_expressao(expressao)) {
        printf("? Expressão bem formada!\n\n");
    } else {
        printf("? Expressão mal formada!\n\n");
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    printf("=== VERIFICADOR DE EXPRESSÕES MATEMÁTICAS ===\n\n");
    
    // Testes com expressões válidas
    printf("--- Expressões Válidas ---\n");
    testar_expressao("(2 + 3) * (4 - 1)");
    testar_expressao("{[2 + (3 * 4)] - 5}");
    testar_expressao("2 + 3"); // Sem parênteses
    testar_expressao("((()))"); // Parênteses aninhados
    testar_expressao("({[]})"); // Diferentes tipos
    
    // Testes com expressões inválidas
    printf("--- Expressões Inválidas ---\n");
    testar_expressao("(2 + 3 * (4 - 1)"); // Fecha um, mas abre dois
    testar_expressao("2 + 3)"); // Fechamento sem abertura
    testar_expressao("((2 + 3)"); // Abertura sem fechamento
    testar_expressao("([)]"); // Ordem incorreta
    testar_expressao("({[}])"); // Tipos misturados incorretamente
    
    // Teste interativo
    printf("--- Teste Interativo ---\n");
    char expressao[100];
    
    printf("Digite uma expressão matemática (ou 'sair' para encerrar):\n");
    
    while (1) {
        printf("> ");
        if (fgets(expressao, sizeof(expressao), stdin) == NULL) break;
        
        // Remove o newline
        expressao[strcspn(expressao, "\n")] = '\0';
        
        if (strcmp(expressao, "sair") == 0) break;
        
        testar_expressao(expressao);
    }
    
    return 0;
}
