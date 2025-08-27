#include <stdio.h>
#include <stdlib.h>

int func_A(int n){
    int c = 0;  //--------------------------------------------1
    int i = 0;  //--------------------------------------------1
    for(i=1; i <= n;i++){//--------------------------------------SOMATÓRIO- LS: N, LI: i = 1, Termo: 1, logo, igual a N
    	c += 1; //--------------------------------------------1
	}
	int j = 0;  //--------------------------------------------1
	for(j=1; j <= n; j++){//--------------------------------------SOMATÓRIO- LS: N, LI: j = 1, Termo: 1, logo, igual a N
		c += 2; //--------------------------------------------1
	}
	
	return c;
}

//Logo, nossa T(n) = 1+1+N+1+N = 2n + 3
//Olhando a T(n), a Função A é de complexidade Big O(n)

int func_B(int n){
	int c = 0; //---------------------------------------------1
	int i = 0; //---------------------------------------------1
	
	for(i=1; i <= n;i++){ //-------------------------------------------------SOMATÓRIO- LS: N, LI: i = 1, Termo: 1 + SOMATÓRIO INTERNO
		int j = 0; //----------------------------------------------1
		for(j=1; j <= n; j++){ //----------------------------------SOMATÓRIO- LS: N, LI: j = 1, Termo: 1, logo, igual a N
			c = c + 1; //-------------------------------------1
		}	
	}
	return c;
}
// Neste caso, a T(n) = 1 + 1 + SOMATÓRIO - LS: N, LI: i=1, Termo: 1 + SOMATÓRIO - LS: N, LI: j=1, Termo: 1
// Logo, o somatório interno, vira N.
//Então temos, T(n) = 1 + 1 + SOMATÓRIO - lS: N, LI: i=1, Termo: 1 + N.
// T(n) = 2 + N + N² 
// Big O(N²)


int func_C(int n){
	int c = 0; //----------------------------------------------------------1
	int i = 0; //----------------------------------------------------------1
	for(i = 1; i < n; i++){//---------------------------------------------SOMATÓRIO- LS: N, LI: i = 1, Termo: 1 + SOMATÓRIO INTERNO.
		int j = 1;//-------------------------------------------1
		for(j = i; j < n; j++){//------------------------------SOMATÓRIO- LS: i, LI: j = i, Termo: 1
			c += 1;//-------------------------------1
		}
	}
	return c;
}

//observe que, o for interno executa uma soma de P.A vezes, por que ?
// quando o i = 0, o For interno com o j, irá de 0 à N, ou seja, N vezes
// quando o i = 1, o For interno com o j, irá de 1 à N, ou seja, N-1 vezes
// quando o i = 2, o For interno com o j, irá de 2 à N, ou seja, N-2 vezes
//até....
// quando o i = N, o For interno com o j, irá de N à N, ou seja, 1 vez

// Temos que, a original T(n) = 1 + 1 + SOMATÓRIO- LS: N, LI: i = 1, Termo: 1 + SOMATÓRIO- LS: N, LI: j = i, Termo: 1
// Se transforma então em: T(n) = 1 + 1 + SOMATÓRIO- LS: N, LI: i = 1, Termo: 1 + i
// Ao final, seguindo a solução com P.A e a regra, fica: 
// T(n) = N.(1 + N)/2 + N + 2 
// T(n) = N²/2 + n/2 + N + 2
// Note que, em "N.(1 + N)/2", segue a regra Sn = N/2.(x1 + xN), logo, o x1 é 1 e xN é N.
// Big O(N²)

int func_D(int n){ //Sucessivas divisões por 2 (log na base 2, quanto maior a base, mais rápido)
	int c = 0; // ---------------------------------------------1
	int i = n; // ---------------------------------------------1
	while ( i > 1){ // ----------------------------------------K = [log n]
		c += 1; //---------------------------------------- 1
		i = i / 2; //------------------------------------- 1
	}
	return c;
}
// Essa função calcula quantas vezes o numero pode ser dividido por 2, até que atinja 0.
// n = 16 -> 8 -> 4 -> 2 -> 1
// nesse exemplo, a variavel C termina valendo 4, pois 2^4 = 16
// n = 40 -> 20 -> 10 -> 5 -> 2 -> 1
// neste outro, a variavel c termina a função valendo 5, pois 2^5 < 40 < 2^6
// Portanto, o numero de iterações do loop é log2 n. 
// Temos a T(n) = 2 + 2[log2 n], sendo a função piso(x), retornando o maior inteiro menor que x.
// Big O(log2 n)

// Note que x, é o valor resultante da divisão, se este valor é decimal, ele pega a maior parte inteira menor que o número.
// se for 2,5, será 2. se for -3,4 será -4, por que -4 é o maior inteiro menor que -4 (-4 esta mais a esquerda na reta numerica)


int func_E(n){
	int c = 0; //----------------------------------------------------------1
	int i = 0; //----------------------------------------------------------1
	for(i = 0; i < n; i++){ //---------------------------------------------SOMATÓRIO- LS: N, LI: i = 1, Termo: log2 n
		c = c + func_D(n);// ----------------log2 n (por que a atribuição, que realiza a chamada de outra função, assume a complexidade da função.
	}
	return c;
}
//Logo temos, T(n) = SOMATÓRIO- LS: N, LI: i = 1, Termo: log2 n, o log2 n é independente, podemos inverte-lo na função.
// ficando assim: T(n) = log2 n . SOMATÓRIO- LS: N, LI: i = 1, Termo: 1 (ou seja, N)
// Portanto, a T(n) = n log2 n + 2
// Big O(n log n)

void main(){
	int n = 10;
	int c = func_A(n);
	printf("Funcao A resultado: %d \n", c);
	c = func_B(n);
	printf("Funcao B resultado: %d \n", c);
	c = func_C(n);
	printf("Funcao C resultado: %d \n", c);
	c = func_D(n);
	printf("Funcao D resultado: %d \n", c);
	c = func_E(n);
	printf("Funcao E resultado: %d \n", c);
	
}
