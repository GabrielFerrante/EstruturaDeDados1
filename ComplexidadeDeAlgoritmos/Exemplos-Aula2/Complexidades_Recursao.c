#include <stdlib.h>
#include <stdio.h>


long long int fibonacci(int n){
	if(n==0){
		return 0;
	}else{
		if(n==1){
			return 1;
		}else{
			return fibonacci(n-1) + fibonacci(n-2); // Dupla recursão.
		}
	}
}
//Para medir a complexidade utilizar a técnica de relação de recorrência.
//Passo 1 : Dividir em sub problemas
//Passo 2 : Abrir a recorrência até encontrar um padrão
//Passo 3: Generalizar para um K arbitrário.
//Passo 4: Validar condição de parada
//Temos inicialmente:
//T(n) = T(n-1) + T(n-2) + O(1), note que o O(1), é a operação de soma.
//Neste caso, podemos simplificar, partindo do pressuposto, que a complexidade T(n-1) é próximo de T(n-2), em caso de n seja grande.
//T(n) =  2.T(n-1) + 1
//Agora, iremos compreender o que é T(n-1):
//T(n-1) = 2.T(n-2) + 1
//Portanto, a T(n) fica:
//T(n) = 2 [ 2.T(n-2)+1] + 1
//Abrindo T(n-2), fica:
//T(n) = 2 { 2 [ 2.T(n-3) + 1] + 1 } + 1
//A T(n) acima, pode ser traduzida para:
//T(n) = 2³ . T(n-3) + [1 + 2¹ + 2²], note que o último termo, é um somatório, sendo o expoente variando.
//Portanto, de forma genérica, para um K arbitrário
//T(n) = 2^k . T(n-k) + SOMATÓRIO- LS:k-1, LI:i=0, Termo: 2^i
//Para resolver este somatório, temos que usar o método da soma telescópica.
//Antes disso, precisamos saber a seguinte jogada matemática, onde 2^i+1 = 2.2^i = 2^i + 2^i
//logo, 2^i = 2^i+1 - 2^i, assim temos um somatório de subtração.
//Portanto, fica: SOMATÓRIO- LS: k-1, LI: i=0, Termo: (2^i+1 - 2^i), 
//aplicando a soma telescópica, 
//o limite superior k-1 substitui o exponencial i+1 do primeiro termo da subtração, e o limite inferior i=0, substitui o segundo termo 2^i
//Transformando o somatório em 2^k - 1.
//Voltando, a T(n) = 2^k.T(n-k)+(2^k-1)
//Vamos verificar a condição de parada para T(0)
//n-k tem que ser igual a 0, para isso, k tem que ser igual a n.
//Portanto, T(n) = 2^n . T(0)(ou seja, 1) + 2^n - 1
//Ficando: T(n) = 2.2^n . -1
//logo: T(n) = 2^n+1 - 1
//Nosso Big O(2^n) exponencial, ou seja, péssimo em eficiência.

void main(){
	
	int n = 50;
	long long int resultado = fibonacci(n);
	printf("Fibonacci: %lld \n", resultado);
	system("PAUSE");
	
}
