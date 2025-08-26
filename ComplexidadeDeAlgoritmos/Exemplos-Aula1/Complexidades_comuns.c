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
// Ao final, seguindo a solução com P.A e a regra, fica: T(n) = N.(1 + N)/2 + 3 = N²/2 + n/2 + 3
// Note que, em "N.(1 + N)/2", segue a regra Sn = N/2.(x1 + xN), logo, o x1 é 1 e xN é N.
// Big O(N²)

void main(){
	
	
}
