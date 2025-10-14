#include <stdio.h>
#include <string.h>

void imprimir_binarios(int n) {
	int i = 1;
    for (i = 1; i <= n; i++) {
        char binario[33] = "";
        int temp = i;
        int posicao = 0;
        
        // Converte para binário (gera na ordem inversa)
        while (temp > 0) {
        	if ((temp % 2) == 1){
        		binario[posicao++] += '1';
        	}else{
        		binario[posicao++] += '0';
			}
            temp /= 2;
        }
        binario[posicao] = '\0';
        
        // Inverte a string
        int j = 0;
        for (j = 0; j < posicao / 2; j++) {
            char temp_char = binario[j];
            binario[j] = binario[posicao - 1 - j];
            binario[posicao - 1 - j] = temp_char;
        }
        
        printf("%3d: %s\n", i, binario);
    }
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    imprimir_binarios(n);
    return 0;
}
