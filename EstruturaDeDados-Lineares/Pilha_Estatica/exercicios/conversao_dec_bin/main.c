#include <stdio.h>
#include "conversor.c"
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
    printf("=== CONVERSOR DECIMAL PARA BIN�RIO ===\n\n");
    
    // Testes com n�meros positivos
    printf("--- N�meros Positivos ---\n");
    decimal_para_binario(0);
    decimal_para_binario(1);
    decimal_para_binario(2);
    decimal_para_binario(5);
    decimal_para_binario(10);
    decimal_para_binario(15);
    decimal_para_binario(16);
    decimal_para_binario(255);
    decimal_para_binario(256);

    // Teste interativo
    printf("\n--- Teste Interativo ---\n");
    printf("Digite n�meros decimais para converter (ou -1 para sair):\n");
    
    int numero;
    while (1) {
        printf("Decimal: ");
        if (scanf("%d", &numero) != 1) {
            printf("Entrada inv�lida!\n");
            while (getchar() != '\n'); // Limpa buffer
            continue;
        }
        
        if (numero == -1) break;
        
        decimal_para_binario(numero);
    }
    
    printf("Programa encerrado.\n");
    return 0;
}
