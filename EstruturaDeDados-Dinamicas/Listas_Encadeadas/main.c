#include <stdio.h>
#include "lista.c"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
    // Criar lista
    Lista* minha_lista = criar_lista();
    
    printf("=== Teste de Lista Encadeada ===\n\n");
    
    // Teste de inser��es
    printf("1. Inser��es:\n");
    inserir_inicio(minha_lista, 10);
    inserir_fim(minha_lista, 30);
    inserir_inicio(minha_lista, 5);
    inserir_posicao(minha_lista, 20, 2);
    imprimir_lista(minha_lista);
    printf("Tamanho: %d\n\n", tamanho(minha_lista));
    
    // Teste de buscas
    printf("2. Buscas:\n");
    int pos = buscar_elemento(minha_lista, 20);
    printf("Elemento 20 encontrado na posi��o: %d\n", pos);
    
    int valor = acessar_posicao(minha_lista, 1);
    printf("Elemento na posi��o 1: %d\n\n", valor);
    
    // Teste de remo��es
    printf("3. Remo��es:\n");
    printf("Removido do in�cio: %d\n", remover_inicio(minha_lista));
    imprimir_lista(minha_lista);
    
    printf("Removido do fim: %d\n", remover_fim(minha_lista));
    imprimir_lista(minha_lista);
    
    printf("Removido da posi��o 1: %d\n", remover_posicao(minha_lista, 1));
    imprimir_lista(minha_lista);
    printf("Tamanho: %d\n\n", tamanho(minha_lista));
    
    // Teste lista vazia
    printf("4. Teste com lista vazia:\n");
    remover_fim(minha_lista); // Remove �ltimo elemento
    printf("Lista vazia? %s\n", esta_vazia(minha_lista) ? "Sim" : "N�o");
    
    // Mais inser��es para demonstrar
    printf("\n5. Mais inser��es:\n");
    int i = 1;
    for (i = 1; i <= 5; i++) {
        inserir_fim(minha_lista, i * 10);
    }
    imprimir_lista(minha_lista);
    printf("Tamanho: %d\n", tamanho(minha_lista));
    
    // Destruir lista
    destruir_lista(minha_lista);
    
    return 0;
}
