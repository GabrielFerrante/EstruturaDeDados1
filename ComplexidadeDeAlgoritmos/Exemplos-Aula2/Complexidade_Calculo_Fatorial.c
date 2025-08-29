#include <stdio.h>
#include <stdlib.h>


long long int fat(int n){
	if(n==1){
		return 1;
	}else{
		return n * fat(n-1);
	}
}

//T(n) = T(n-1) + O(1)
//Abrindo
//T(n) = T(n-2) + 1 + 1
//Abrindo
//T(n) = T(n-3) + 1 + 1 + 1 (Padrão observavel)
//Para um K arbitrário
// T(n) = T(n-k) + k.1
//Lembrar que a condição de parada é T(1), onde n-k = 1 quando k = n-1
//T(n) = T(1) (ou seja, 1) + (n-1).1
//T(n) = 1 + n-1 
//T(n) = n
//Big O(n)


void main(){
	
	int n = 10;
	long long int resultado = fat(n);
	printf("Resultado do Fatorial de %d, eh: %lld\n", n, resultado);
	system("PAUSE");
}
