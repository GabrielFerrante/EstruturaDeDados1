#include <stdio.h>
#include <string.h>
#include "deque_palindromo.c"

void testar_palindromo_basico() {
    printf("=== TESTES BASICOS DE PALINDROMOS ===\n\n");
    
    char *testes[] = {
        "arara",
        "ovo",
        "radar",
        "reler",
        "ana",
        "osso",
        "ama",
        "somos",
        "reviver",
        "casa",
        "computador",
        "python",
        "Ame a ema",
        "A base do teto desaba",
        "A cara rajada da jararaca",
        "Socorram-me subi no onibus em Marrocos"
    };
    
    int num_testes = sizeof(testes) / sizeof(testes[0]);
    int i = 0;
    for (i = 0; i < num_testes; i++) {
        printf("\n--- Teste %d ---\n", i + 1);
        int resultado = eh_palindromo(testes[i]);
        printf("Palavra: '%s'\n", testes[i]);
        printf("Resultado: %s\n", resultado ? "E palindromo " : "Nao e palindromo ?");
    }
}

void testar_palindromo_detalhado() {
    printf("\n=== TESTES DETALHADOS ===\n\n");
    
    char *testes_detalhados[] = {
        "arara",
        "ovo", 
        "casa",
        "reviver"
    };
    
    int num_testes = sizeof(testes_detalhados) / sizeof(testes_detalhados[0]);
    int i = 0;
    for ( i = 0; i < num_testes; i++) {
        eh_palindromo_detalhado(testes_detalhados[i]);
        printf("\n");
    }
}

void testar_frases_complexas() {
    printf("\n=== TESTES COM FRASES COMPLEXAS ===\n\n");
    
    char *frases[] = {
        "Ame a ema",
        "A base do teto desaba",
        "A cara rajada da jararaca",
        "Socorram-me subi no onibus em Marrocos",
        "Anotaram a data da maratona",
        "A torre da derrota"
    };
    
    int num_frases = sizeof(frases) / sizeof(frases[0]);
    int i = 0;
    for ( i = 0; i < num_frases; i++) {
        printf("Frase: '%s'\n", frases[i]);
        
        // Pré-processa a frase: remove espaços e converte para minúsculo
        char frase_limpa[100];
        int idx = 0;
        int j = 0;
        for (j = 0; frases[i][j] != '\0'; j++) {
            char c = frases[i][j];
            if (isalpha(c)) {
                frase_limpa[idx++] = tolower(c);
            }
        }
        frase_limpa[idx] = '\0';
        
        printf("Frase limpa: '%s'\n", frase_limpa);
        
        int resultado = eh_palindromo(frase_limpa);
        printf("Resultado: %s\n\n", resultado ? "É palindromo " : "Nao e palindromo ");
    }
}

void menu_interativo() {
    printf("\n=== MENU INTERATIVO - VERIFICADOR DE PALINDROMOS ===\n");
    
    char palavra[100];
    
    do {
        printf("\nDigite uma palavra/frase (ou 'sair' para encerrar): ");
        
        // Lê a entrada do usuário
        if (fgets(palavra, sizeof(palavra), stdin) == NULL) {
            break;
        }
        
        // Remove o newline do final
        palavra[strcspn(palavra, "\n")] = '\0';
        
        // Verifica se o usuário quer sair
        if (strcmp(palavra, "sair") == 0) {
            printf("Encerrando programa...\n");
            break;
        }
        
        if (strlen(palavra) == 0) {
            printf("Por favor, digite uma palavra.\n");
            continue;
        }
        
        printf("\nEscolha o modo de verificacao:\n");
        printf("1. Modo simples\n");
        printf("2. Modo detalhado\n");
        printf("Opcao: ");
        
        int opcao;
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado
        
        if (opcao == 1) {
            eh_palindromo(palavra);
        } else if (opcao == 2) {
            eh_palindromo_detalhado(palavra);
        } else {
            printf("Opcao invalida!\n");
        }
        
    } while (1);
}

int main() {
    printf("=== VERIFICADOR DE PALINDROMOS USANDO DEQUE ===\n\n");
    
    int opcao;
    
    do {
        printf("Escolha uma opcao:\n");
        printf("1. Testes basicos\n");
        printf("2. Testes detalhados\n");
        printf("3. Frases complexas\n");
        printf("4. Modo interativo\n");
        printf("5. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer
        
        switch (opcao) {
            case 1:
                testar_palindromo_basico();
                break;
            case 2:
                testar_palindromo_detalhado();
                break;
            case 3:
                testar_frases_complexas();
                break;
            case 4:
                menu_interativo();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
        printf("\n");
    } while (opcao != 5);
    
    return 0;
}
