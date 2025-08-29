#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

float euler_exponencial(x, n){ //x é o expoente, e n é o limite superior 
	if(n==0){
		return 0;
	}else{
		return (pow(x, n)/fat(n))+euler_exponencial(x, n-1);
	}
}

//Usando a regra da recorrência
//T(n) = T(n-1) + O(1) + O(N), note que, O(1) é a soma e O(N) é a complexidade da função fat
//T(n) = T(n-1) + O(N), note que o O(1) desaparece pois é utilizado somente o maior.
//Logo temos a seguinte abrimento:
//T(n) = T(n-1) + c.n, note que c.n, é igual a O(N)
//T(n) = T(n-2) + c.(n-1) + c.n
//T(n) = T(n-3) + c.(n-2) + c.(n-1) + c.n
//Para um K arbitrário:
//T(n) = T(n-k) + c.[1 + 2 + 3 + ...+ n], note que é igual uma soma de P.A, ou seja, n.(n+1)/2
//Na condição de parada:
//n-k = 0, logo, k tem que ser igual a n
//T(n) = T(0) (ou seja 1) + c . n(n+1)/2
//T(n) = 1 + c. (n² + n)/2 
//Ficando Big O(n²)

void main(){
	
	int n = 10;
	long long int resultado = fat(n);
	printf("Resultado do Fatorial de %d, eh: %lld\n", n, resultado);
	system("PAUSE");
}
