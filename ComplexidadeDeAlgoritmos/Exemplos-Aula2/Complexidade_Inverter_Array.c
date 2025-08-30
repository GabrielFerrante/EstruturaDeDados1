#include <stdio.h>
#include <stdlib.h>

// Primeiro, precisamos de uma função de troca.
// Note que, quando selecionamos para troca, duas posições do array, estamos tendo um problema N-2, ao invés de N
void swap(int*L, int a, int b){
	int temp;
	temp = L[a]; //-----------------------1
	L[a] = L[b]; //-----------------------1
	L[b] = temp; //-----------------------1
	
}
// Note que a função é simples, com complexidade Big O(1)
//Para fazer a inversão de forma recursiva, precisamos entender a condição de parada.
// Temos que ter o index do fim <= o index do inicio, lembrando, o fim é iniciado pela ultima posição do array e inicio é o primeiro index

void insert(int *L, int inicio, int fim){
	printf("Inicio : %d | Fim : %d\n", inicio, fim);
	
	if(fim <= inicio){
		printf("Fim da recursao\n");
	}else{
		printf("%d e %d\n", L[inicio], L[fim]);
		swap(L, inicio, fim); // ------------ Big O(1)
		insert(L, inicio+1, fim-1);
	}
}

//Calculando a complexidade
// T(n) = T(n-2) + O(1) (ou seja 1)
// Abrindo recorrência de T(n-2)
// T(n) = T(n-4) + 1 + 1, note que é "n-4", pois cada iteração, são sempre menos 2 numeros da lista.
// T(n) = T(n-6) + 1 + 1 + 1
//Entendendo o padrão:
//O número de somas de 1, é igual a k, no caso, k = 3
//O número de redução de n, ou seja, n-6, 6 é igual a 2.k.
//Para um K arbitrário temos:
//T(n) = T(n-2.k) + k.1
//Na condição de parada, onde T(0) tem que ser:
//Para n-2.k = 0, o "n" tem que ser "2.k" e "k" tem que ser "n/2"
//Portando,
//T(n) = T(0) + (n/2) . 1
//T(n) = 1 + (n/2) . 1
//Complexidade de Big O(n)


void main(){
	int arr[8] = {27,0,3,3,25,6,22,10};
	int tamanho = sizeof(arr) / sizeof(arr[0]);
	printf("Lista inicial\n");
	int i=0;
	for(i=0; i < tamanho; i++){
		printf("%d,", arr[i]);
	}
	printf("\n");
	insert(arr, 0, tamanho-1); // Tamanho-1 por que quando é calculado, ele considera 8, mas os indexes vão até 7
	i=0;
	printf("Lista final\n");
	for(i=0; i < tamanho; i++){
		printf("%d,", arr[i]);
	}
	printf("\n");
	
	system("PAUSE");
	
}
