#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Estrutura para representar um número grande
typedef struct {
    int* digits;   // Array de dígitos na ordem INVERSA (ex: 123 -> {3, 2, 1})
    int length;    // Número de dígitos
} BigInt;

// --- Protótipos das funções (código completo abaixo da main) ---
void freeBigInt(BigInt* n);
BigInt* addBigInt(BigInt* a, BigInt* b);
void shiftLeft(BigInt* n, int places);
BigInt* createBigIntFromString(const char* s);
long long toLong(BigInt* n);
BigInt* fromLong(long long val);
void printBigInt(BigInt* n);


BigInt* multiply_4_partitions(BigInt* a, BigInt* b) {
    int n = fmax(a->length, b->length);

    // --- Base da Recursão: se os números são pequenos, use multiplicação normal ---
    if (n <= 4) {
        long long val_a = toLong(a);
        long long val_b = toLong(b);
        return fromLong(val_a * val_b);
    }
    
    // --- Particione a e b em a1, a2, b1, b2 ---
    int mid = n / 2;

    // Criamos "visualizações" (views) das metades dos números
    BigInt* a1 = malloc(sizeof(BigInt));
    BigInt* a2 = malloc(sizeof(BigInt));
    BigInt* b1 = malloc(sizeof(BigInt));
    BigInt* b2 = malloc(sizeof(BigInt));

    // Parte baixa (a2, b2) - os primeiros 'mid' dígitos
    a2->length = fmin(mid, a->length);
    a2->digits = a->digits;
    b2->length = fmin(mid, b->length);
    b2->digits = b->digits;

    // Parte alta (a1, b1) - o restante dos dígitos
    a1->length = a->length > mid ? a->length - mid : 0;
    a1->digits = a->digits + mid;
    b1->length = b->length > mid ? b->length - mid : 0;
    b1->digits = b->digits + mid;

    // --- As 4 chamadas recursivas, como no pseudocódigo ---
    BigInt* A = multiply_4_partitions(a1, b1); // A = a1 * b1
    BigInt* B = multiply_4_partitions(a1, b2); // B = a1 * b2
    BigInt* C = multiply_4_partitions(a2, b1); // C = a2 * b1
    BigInt* D = multiply_4_partitions(a2, b2); // D = a2 * b2

    // --- Combina os resultados: P = A*10^n + (B+C)*10^(n/2) + D ---

    // 1. Calcula (B+C)
    BigInt* sum_BC = addBigInt(B, C);
    
    // 2. Desloca os termos (multiplica por potências de 10)
    // A*10^n  (n é aproximadamente 2*mid)
    shiftLeft(A, 2 * mid);
    // (B+C)*10^(n/2)
    shiftLeft(sum_BC, mid);

    // 3. Soma tudo
    BigInt* partial_result = addBigInt(A, sum_BC);
    BigInt* final_result = addBigInt(partial_result, D);
    
    // --- Libera toda a memória intermediária ---
    free(a1); free(a2); free(b1); free(b2);
    freeBigInt(A);
    freeBigInt(B);
    freeBigInt(C);
    freeBigInt(D);
    freeBigInt(sum_BC);
    freeBigInt(partial_result);

    return final_result;
}


// --- Função Principal para Teste ---
int main() {
    BigInt* num1 = createBigIntFromString("123456789");
    BigInt* num2 = createBigIntFromString("987654321");

    printf("Numero 1: "); printBigInt(num1);
    printf("Numero 2: "); printBigInt(num2);
    
    BigInt* product = multiply_4_partitions(num1, num2);

    printf("Produto:  "); printBigInt(product);


    // Libera a memória final
    freeBigInt(num1);
    freeBigInt(num2);
    freeBigInt(product);

    return 0;
}


void trim(BigInt* n) {
    while (n->length > 1 && n->digits[n->length - 1] == 0) {
        n->length--;
    }
}

BigInt* createBigIntFromString(const char* s) { //Função para criar variaveis desse tipo.
    int len = strlen(s);
    if (len == 0) { // Lida com string vazia
        len = 1;
        s = "0";
    }
    BigInt* n = malloc(sizeof(BigInt));
    n->digits = malloc(sizeof(int) * len);
    n->length = len;
    int i = 0;
    for (i = 0; i < len; i++) {
        n->digits[i] = s[len - 1 - i] - '0';
    }
    trim(n);
    return n;
}

void freeBigInt(BigInt* n) { // Função para liberar da memória
    if (n) {
        free(n->digits);
        free(n);
    }
}

void printBigInt(BigInt* n) {
    if (!n) {
        printf("(null)\n");
        return;
    }
    int i = 0;
    for (i = n->length - 1; i >= 0; i--) {
        printf("%d", n->digits[i]);
    }
    printf("\n");
}

BigInt* addBigInt(BigInt* a, BigInt* b) {
    int maxLen = fmax(a->length, b->length);
    BigInt* result = malloc(sizeof(BigInt));
    result->digits = calloc(maxLen + 1, sizeof(int));
    result->length = maxLen;
    int carry = 0;
    int i = 0;
    for (i = 0; i < maxLen; i++) {
        int d1 = (i < a->length) ? a->digits[i] : 0;
        int d2 = (i < b->length) ? b->digits[i] : 0;
        int sum = d1 + d2 + carry;
        result->digits[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry > 0) {
        result->digits[maxLen] = carry;
        result->length = maxLen + 1;
    }
    return result;
}

void shiftLeft(BigInt* n, int places) {
    if ((n->length == 1 && n->digits[0] == 0) || places == 0) return;
    int new_len = n->length + places;
    n->digits = realloc(n->digits, sizeof(int) * new_len);
    memmove(n->digits + places, n->digits, n->length * sizeof(int));
    memset(n->digits, 0, places * sizeof(int));
    n->length = new_len;
}

long long toLong(BigInt* n) {
    long long val = 0;
    int i = n->length - 1;
    for (i = n->length - 1; i >= 0; i--) {
        val = val * 10 + n->digits[i];
    }
    return val;
}

BigInt* fromLong(long long val) {
    char buffer[30];
    sprintf(buffer, "%lld", val);
    return createBigIntFromString(buffer);
}
