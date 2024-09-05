#include <stdio.h>
#include <math.h>

int somadosdigitos(int n);
int QtdDigitos(int num);
void parImpar(int n);
int EhPar(int num);
void valorPrimo(int n);
int EhPrimo (int num);

int main (){
	int num = 0, i = 1, dig = 11, res = 12;
	
	scanf("%d", &num);

	res = num;

	if(num>10){
		
		while(res > 9){
			res = somadosdigitos(num);
			printf("%d ",res);
			parImpar(res);
			valorPrimo(res);
			num = res;
		}
	} else{
		printf("%d ", num);
		parImpar(res);
		valorPrimo(res);
	}
	
}

int QtdDigitos(int num){
	int den = 1, dig = 1, div = 1;
	
	for(den = 10, dig = 1; div != 0; den = den*10, dig++ ){
		div = num/den;
	}
	dig--;
	return dig;
}

int somadosdigitos(int n){
	int dig = 0, den = 1, div = 0, soma = 0, exp = 1, alg = 1;
	
	dig = QtdDigitos(n);
	exp = dig--;
	
	for(den = pow (10, exp) ; den >= 1 ; den = den/10){
		alg = n/den;
		n = n%den;
		soma = soma + alg;
	}

	
	return soma;
}

int EhPar(int num){
	int resto = 2;
	resto = num%2;
	
	if(resto == 0){
		return 1;
	}
	else{
		return 0;
	}
}


void parImpar(int n){

	if(EhPar(n)){
		printf("Par ");
	}
	else{
		printf("Impar ");
	}

}

void valorPrimo(int n){
	if(EhPrimo(n)){
		printf("Primo\n");
	}
	else{
		printf("Nao e primo\n");
	}
}

int EhPrimo (int num){
	int resto = 0, den = 2;
	if(num == 1 || num == 0){
		return 0;
	}
	
	for(den = 2 ; den < num ; den++){
		resto = num%den;
		if(resto == 0){
			return 0;
		}
	}
//	printf("primo");
	return 1;
} 



