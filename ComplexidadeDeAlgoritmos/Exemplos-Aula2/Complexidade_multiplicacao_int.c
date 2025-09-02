#include <stdio.h>   // Biblioteca para entrada/saída (printf, etc.)
#include <stdlib.h>  // Biblioteca para alocação de memória (malloc, free, realloc)
#include <string.h>  // Biblioteca para manipulação de strings (strlen, memmove, memset)
#include <math.h>    // Biblioteca para funções matemáticas (fmax, fmin)

// Estrutura para representar números grandes com dígitos armazenados em ordem reversa
typedef struct {
    int* digits;   // Array de dígitos (ordem reversa: dígito menos significativo primeiro)
    int length;    // Número atual de dígitos no array
} BigInt;

// Protótipos das funções
void freeBigInt(BigInt* n);  // Libera memória alocada para BigInt
BigInt* addBigInt(BigInt* a, BigInt* b);  // Soma dois BigInts
void shiftLeft(BigInt* n, int places);  // Desloca dígitos (multiplica por 10^places)
BigInt* createBigIntFromString(const char* s);  // Cria BigInt a partir de string
long long toLong(BigInt* n);  // Converte BigInt para long long
BigInt* fromLong(long long val);  // Cria BigInt a partir de long long
void printBigInt(BigInt* n);  // Imprime BigInt na ordem correta

// Função de multiplicação usando divisão e conquista (4 partições)
BigInt* multiply_4_partitions(BigInt* a, BigInt* b) {
    // Determina o tamanho do maior número
    int n = fmax(a->length, b->length);

    // Caso base: números pequenos, converte para long long para multiplicação direta
    if (n <= 4) {
        long long val_a = toLong(a);
        long long val_b = toLong(b);
        return fromLong(val_a * val_b);
    }
    
    // Calcula ponto de divisão (metade do tamanho)
    int mid = n / 2;

    // Cria visões (views) das metades sem copiar dados
    BigInt* a1 = malloc(sizeof(BigInt));  // Parte alta de a
    BigInt* a2 = malloc(sizeof(BigInt));  // Parte baixa de a
    BigInt* b1 = malloc(sizeof(BigInt));  // Parte alta de b
    BigInt* b2 = malloc(sizeof(BigInt));  // Parte baixa de b

    // Configura parte baixa de a (primeiros 'mid' dígitos)
    a2->length = fmin(mid, a->length);
    a2->digits = a->digits;  // Aponta para início do array original

    // Configura parte baixa de b (primeiros 'mid' dígitos)
    b2->length = fmin(mid, b->length);
    b2->digits = b->digits;  // Aponta para início do array original

    // Configura parte alta de a (dígitos restantes)
    a1->length = a->length > mid ? a->length - mid : 0;
    //A linha usa um operador ternário para determinar o comprimento de `a1`. A condição é:
	// Se o comprimento de `a` for maior que `mid`, então a parte alta `a1` terá comprimento `a->length - mid`.
	//Caso contrário (se o comprimento de `a` for menor ou igual a `mid`), então a parte alta `a1` terá comprimento 0.
   
    a1->digits = a->digits + mid;  // Aponta para metade do array original

    // Configura parte alta de b (dígitos restantes)
    b1->length = b->length > mid ? b->length - mid : 0;
    b1->digits = b->digits + mid;  // Aponta para metade do array original

    // Chamadas recursivas para as 4 multiplicações:
    BigInt* A = multiply_4_partitions(a1, b1);  // a1 * b1
    BigInt* B = multiply_4_partitions(a1, b2);  // a1 * b2
    BigInt* C = multiply_4_partitions(a2, b1);  // a2 * b1
    BigInt* D = multiply_4_partitions(a2, b2);  // a2 * b2

    // Calcula soma B + C
    BigInt* sum_BC = addBigInt(B, C);
    
    // Desloca A para esquerda por 2*mid posições (multiplica por 10^(2*mid))
    shiftLeft(A, 2 * mid);
    // Desloca soma B+C para esquerda por mid posições (multiplica por 10^mid)
    shiftLeft(sum_BC, mid);

    // Soma os componentes deslocados
    BigInt* partial_result = addBigInt(A, sum_BC);
    BigInt* final_result = addBigInt(partial_result, D);
    
    // Libera memória das estruturas temporárias
    free(a1); free(a2); free(b1); free(b2);
    freeBigInt(A);
    freeBigInt(B);
    freeBigInt(C);
    freeBigInt(D);
    freeBigInt(sum_BC);
    freeBigInt(partial_result);

    return final_result;
}

// Função principal de teste
int main() {
    // Cria números grandes a partir de strings
    BigInt* num1 = createBigIntFromString("123456789");
    BigInt* num2 = createBigIntFromString("987654321");

    // Imprime os números
    printf("Numero 1: "); printBigInt(num1);
    printf("Numero 2: "); printBigInt(num2);
    
    // Calcula produto usando multiplicação por partições
    BigInt* product = multiply_4_partitions(num1, num2);

    // Imprime resultado
    printf("Produto:  "); printBigInt(product);

    // Libera memória final
    freeBigInt(num1);
    freeBigInt(num2);
    freeBigInt(product);

    return 0;
}

// Remove zeros não significativos à esquerda (fim do array na representação reversa)
void trim(BigInt* n) {
    while (n->length > 1 && n->digits[n->length - 1] == 0) {
        n->length--;
    }
}

// Cria BigInt a partir de string
BigInt* createBigIntFromString(const char* s) {
    int len = strlen(s);
    if (len == 0) {  // Trata string vazia como zero
        len = 1;
        s = "0";
    }
    BigInt* n = malloc(sizeof(BigInt));
    n->digits = malloc(sizeof(int) * len);
    n->length = len;
    // Preenche array na ordem reversa (dígito menos significativo primeiro)
    int i = 0;
    for (i = 0; i < len; i++) {
        n->digits[i] = s[len - 1 - i] - '0';  // Converte char para int
    }
    trim(n);  // Remove zeros não significativos
    return n;
}

// Libera memória de BigInt
void freeBigInt(BigInt* n) {
    if (n) {
        free(n->digits);  // Libera array de dígitos
        free(n);          // Libera estrutura
    }
}

// Imprime BigInt na ordem correta (do mais significativo para o menos)
void printBigInt(BigInt* n) {
    if (!n) {
        printf("(null)\n");
        return;
    }
    // Imprime do último dígito (mais significativo) para o primeiro
    int i = 0;
    for (i = n->length - 1; i >= 0; i--) {
        printf("%d", n->digits[i]);
    }
    printf("\n");
}

// Soma dois BigInts
BigInt* addBigInt(BigInt* a, BigInt* b) {
    int maxLen = fmax(a->length, b->length);
    BigInt* result = malloc(sizeof(BigInt));
    result->digits = calloc(maxLen + 1, sizeof(int));  // Aloca com zeros
    result->length = maxLen;
    int carry = 0;
    int i = 0;
    for (i = 0; i < maxLen; i++) {
        // Obtém dígitos de a e b (ou 0 se acabaram)
        int d1 = (i < a->length) ? a->digits[i] : 0;
        int d2 = (i < b->length) ? b->digits[i] : 0;
        int sum = d1 + d2 + carry;
        result->digits[i] = sum % 10;  // Dígito resultante
        carry = sum / 10;              // Carry para próxima posição
    }
    if (carry > 0) {  // Se sobrou carry, aumenta tamanho
        result->digits[maxLen] = carry;
        result->length = maxLen + 1;
    }
    return result;
}

// Desloca dígitos para esquerda (adiciona zeros no final na representação reversa)
void shiftLeft(BigInt* n, int places) {
    if ((n->length == 1 && n->digits[0] == 0) || places == 0) return;
    int new_len = n->length + places;
    n->digits = realloc(n->digits, sizeof(int) * new_len);
    // Move dígitos existentes para o final
    memmove(n->digits + places, n->digits, n->length * sizeof(int));
    // Preenche início com zeros
    memset(n->digits, 0, places * sizeof(int));
    n->length = new_len;
}

// Converte BigInt para long long (apenas para números pequenos)
long long toLong(BigInt* n) {
    long long val = 0;
    // Percorre do mais significativo para o menos (ordem reversa no array)
    int i = n->length - 1;
    for (i = n->length - 1; i >= 0; i--) {
        val = val * 10 + n->digits[i];
    }
    return val;
}

// Cria BigInt a partir de long long
BigInt* fromLong(long long val) {
    char buffer[30];  // Buffer para conversão
    sprintf(buffer, "%lld", val);
    return createBigIntFromString(buffer);
}
