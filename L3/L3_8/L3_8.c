#include <stdio.h>
#include <math.h>

int verificaPrimo(int n);
int transformaPrimo(int n);
int verificaNegativo(int n);

int main (){
	int linha = 0, coluna = 0, l = 1, c = 1, ehPrimo = 0, ehNeg = 0, trans = 0, valor = 0;
	char lixo = 'a';
	scanf ("%d %d%c", &linha, &coluna, &lixo);

	
	for (l = 1 ; l <= linha; l++){
		for (c = 1 ; c <= coluna ; c++){
			if (c == 1){
				printf("	");
				scanf("%d%c", &valor, &lixo);
			} else {
			scanf("%d%c", &valor, &lixo);
			}
			trans = transformaPrimo(valor);
			if (c == 1){
				printf("%d ", trans);
			} else {
				printf("%d ", trans);
			}
			if(c == coluna){
				printf("\n");
			}
		}
		
	}

	
}

int verificaPrimo(int n){
	
	int count = 0, div = 0, result = 1;

	if ( n == 2 || n == -2){
		return 1;
	} else if(n == 1 || n == -1){
		return 0;
	}
	
	if(n>0){
		for (count = 2 ; count < n ; count++){
			result = 1;
			div = n%count;
			if (div == 0){ 
				result = 0;
				break;
			} 
		}
		
	}
	
	if (n<0){
		for (count = -2 ; count > n ; count--){
			result = 1;
			div = n%count;
			if (div == 0){ 
				result = 0;
				break;
			} 
		}
		
	}
	return result;	
}
	
		
		



int verificaNegativo(int n){
	int result = 0;
	if (n >= 0){
		result = 0;
	}
	if (n < 0){
		result = 1;
	}
	return result;
}

int transformaPrimo(int n){
	int result = 0, count = 0, i = 1, retorno = 0;
	
	if((n > 32000) || (n < -32000)){
		result = n;	
	} else if(verificaNegativo(n)){	
		for (count = n ; i ; count--){
			retorno = verificaPrimo(count);
			if (retorno == 0){
				continue;
			} else if (retorno == 1){
				result = count;
				break;
			}	
		}
	} else {
		for (count = n ; i ; count++){
			retorno = verificaPrimo(count);
			if (retorno == 0){
				continue;
			} else if (retorno == 1){
				result = count;
				break;
			}	
		}	
	} 
	
	if (n == 0){
		result = 2;
	}
	
	if((result > 32000) || (result < -32000)){
		result = n;	
	}
	
	return result; 	
}
