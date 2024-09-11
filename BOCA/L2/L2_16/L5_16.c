#include <stdio.h>

int main (){
	int n = 1, i = 1, menor = 999999, aux = 0, resultado = 0, print1 = 0, print2 = 0, j = 2, k = 1, tam = 0, l = 0;
	char c;

	while (i){
	
	
		resultado = scanf("%d", &n);
		if(n >= -32000 && n <= 32000){
		if(resultado == 1){
		
			if(n<menor || menor == 999999){
				menor = n; 
				
			} 
		
		
		} else  {
			break;
		}

		}
		n = 1;
  	}
	
	n = 1;
	
		while (i){

	
				resultado = scanf("%c%d",&c, &n);
				if(n >= -32000 && n <= 32000){
				
					if(resultado == 2){
		
						if(n == menor && j == 2){
							print1 = aux; 
							j++;
							l++;
			
						} 
						if(n == menor){
						print2 = aux; 
				
			
						}
					} else {
				
					break;
				
				
				}	
		} else {
			n = 1;

			
		}
	
		aux++;
		}

		if (print1 == 0 && print2 == 0 && l == 0){
	
			print1 = aux;
			print2 = aux;
		}
		
		printf("%d %d %d", menor, print1, print2);
		return 0;
}
	

	
