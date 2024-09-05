#include <stdio.h>
#include <math.h>

int EhPalindromo(int num); 

int main (){
	int num = 0, aux = 0, i = 1, result = 0, ajuda = 0;
	char lixo = 'a';
	
	while (i){
		ajuda = scanf("%d%c",&num, &lixo);
		if 	(ajuda != 0 && ajuda!= -1){
			result = EhPalindromo(num);
			if (result == 1){
				printf("S\n");
			} else {
				printf("N\n");
			}
		} else {
			break;
		}
	}
	return 0;	
}

int EhPalindromo(int num){
	int soma = 0, algarismo = 1, div = 1, aux = 0, div2 = 1, i = 1, j = 0, armazem = 0, k = 1, result = 0;
	
	armazem = num;
	div = num;
	
	for (aux = 10; div != 0; aux*10){
		div = div/aux;
		if(div != 0){
			algarismo++;
		} else {
			break;
		}
	}
	i = algarismo - 1;

	for (j = pow(10,i), k = 1  ; i >= 0 ; i--, k = k*10){
		j = pow(10,i);
		div2 = num/j;
		soma = soma + div2*k;
		num = num%j;
	}
	
	if (soma == armazem){
		result = 1;
	} else {
		result = 0;
	}
	
	return result; 
} 
