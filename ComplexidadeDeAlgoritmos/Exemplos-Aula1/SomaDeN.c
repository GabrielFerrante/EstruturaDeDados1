#include <stdio.h>
#include <stdlib.h>

int sum_of_n(int n){
	int soma = 0;
	int i = 0; // ------------------------1
	for (i = 0; i < n; i++){ // ----------------SOMATÓRIO - LS: N, LI: i = 1, TERMO: 1 (VAMOS CHAMAR DE S, para simplificar)
		soma = soma + i;//------------------1
	}
	return soma;
}
// S = (1+1+1+1+1....) N VEZES, logo, N . 1 = N
// LOGO
// T(N) = N + 1 
// NOTAÇÃO Big O(n)

void main(){
	
	int soma = sum_of_n(10);
	printf("%d", soma);
}
