#include <stdio.h>
#include <math.h>

int main (){
	int qtd = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0, num = 0;
	char car = 'a', aspas = 'a';
	
	scanf ("%d ", &qtd);
	
	if (qtd == 1){
		scanf ("%d ", &n1);
		scanf("%c", &aspas);
		
		while (car != '"'){
			scanf ("%c",&car);
			if (car != '"' && car != '%'){
				printf("%c", car);
			} 
			
			if (car == '%'){
				scanf("%d", &num);
				if (num == 1){
					printf("%d", n1);
				} else {
					printf("ERRO");
				}
			} 
			
		}
		
	}
	
	if (qtd == 2){
		scanf ("%d %d ", &n1, &n2);
		scanf("%c", &aspas);
		
		while (car != '"'){
			scanf ("%c",&car);
			if (car != '"' && car != '%'){
				printf("%c", car);
			} 
			
			if (car == '%'){
				scanf("%d", &num);
				if (num == 1){
				printf("%d", n1);
				} else if (num == 2){
				printf("%d", n2);
				} else {
				printf("ERRO");
				}
				
			}
			
		}
	}
	
	if (qtd == 3){
		scanf ("%d %d %d ", &n1, &n2, &n3);
		scanf("%c", &aspas);
		
		while (car != '"'){
			scanf ("%c",&car);
			if (car != '"' && car != '%'){
				printf("%c", car);
			} 
			
			if (car == '%'){
				scanf("%d", &num);
				if (num == 1){
				printf("%d", n1);
				} else if (num == 2){
				printf("%d", n2);
				} else if (num == 3){
				printf("%d", n3);
				} else {
				printf("ERRO");
				}
				
			}
			
		}
	}
	
	if (qtd == 4){
		scanf ("%d %d %d %d ", &n1, &n2, &n3, &n4);
		scanf("%c", &aspas);
		
		while (car != '"'){
			scanf ("%c",&car);
			if (car != '"' && car != '%'){
				printf("%c", car);
			} 
			
			if (car == '%'){
				scanf("%d", &num);
				if (num == 1){
				printf("%d", n1);
				} else if (num == 2){
				printf("%d", n2);
				} else if (num == 3){
				printf("%d", n3);
				} else if (num == 4){
					printf("%d", n4);
				} else {
				printf("ERRO");
				}
				
			}
			
		}
	}
	
	if (qtd == 5){
		scanf ("%d %d %d %d %d ", &n1, &n2, &n3, &n4, &n5);
		scanf("%c", &aspas);
		
		while (car != '"'){
			scanf ("%c",&car);
			if (car != '"' && car != '%'){
				printf("%c", car);
			} 
			
			if (car == '%'){
				scanf("%d", &num);
				if (num == 1){
				printf("%d", n1);
				} else if (num == 2){
				printf("%d", n2);
				} else if (num == 3){
				printf("%d", n3);
				} else if (num == 4){
					printf("%d", n4);
				} else if (num == 5){
					printf("%d", n5);
				} else {
				printf("ERRO");
				}
				
				
			}
			
		}
	}
	
	if (qtd == 6){
		scanf ("%d %d %d %d %d %d ", &n1, &n2, &n3, &n4, &n5, &n6);
		scanf("%c", &aspas);
		
		while (car != '"'){
			scanf ("%c",&car);
			if (car != '"' && car != '%'){
				printf("%c", car);
			} 
			
			if (car == '%'){
				scanf("%d", &num);
				if (num == 1){
				printf("%d", n1);
				} else if (num == 2){
				printf("%d", n2);
				} else if (num == 3){
				printf("%d", n3);
				} else if (num == 4){
					printf("%d", n4);
				} else if (num == 5){
					printf("%d", n5);
				} else if (num == 6){
					printf("%d", n6);
				} else {
				printf("ERRO");
				}
				
				
			}
			
		}
	}
	
	if (qtd == 7){
		scanf ("%d %d %d %d %d %d %d ", &n1, &n2, &n3, &n4, &n5, &n6, &n7);
		scanf("%c", &aspas);
		
		while (car != '"'){
			scanf ("%c",&car);
			if (car != '"' && car != '%'){
				printf("%c", car);
			} 
			
			if (car == '%'){
				scanf("%d", &num);
				if (num == 1){
				printf("%d", n1);
				} else if (num == 2){
				printf("%d", n2);
				} else if (num == 3){
				printf("%d", n3);
				} else if (num == 4){
					printf("%d", n4);
				} else if (num == 5){
					printf("%d", n5);
				} else if (num == 6){
					printf("%d", n6);
				} else if (num == 7){
					printf("%d", n7);
				} else {
				printf("ERRO");
				}
				
			}
			
		}
	}
	
	if (qtd == 8){
		scanf ("%d %d %d %d %d %d %d %d ", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8);
		scanf("%c", &aspas);
		
		while (car != '"'){
			scanf ("%c",&car);
			if (car != '"' && car != '%'){
				printf("%c", car);
			} 
			
			if (car == '%'){
				scanf("%d", &num);
				if (num == 1){
				printf("%d", n1);
				} else if (num == 2){
				printf("%d", n2);
				} else if (num == 3){
				printf("%d", n3);
				} else if (num == 4){
					printf("%d", n4);
				} else if (num == 5){
					printf("%d", n5);
				} else if (num == 6){
					printf("%d", n6);
				} else if (num == 7){
					printf("%d", n7);
				} else if (num == 8){
					printf("%d", n8);
				}
				
			}
			
		}
	}
		if (qtd == 9){
		scanf ("%d %d %d %d %d %d %d %d %d ", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9);
		scanf("%c", &aspas);
		
		while (car != '"'){
			scanf ("%c",&car);
			if (car != '"' && car != '%'){
				printf("%c", car);
			} 
			
			if (car == '%'){
				scanf("%d", &num);
				if (num == 1){
				printf("%d", n1);
				} else if (num == 2){
				printf("%d", n2);
				} else if (num == 3){
				printf("%d", n3);
				} else if (num == 4){
					printf("%d", n4);
				} else if (num == 5){
					printf("%d", n5);
				} else if (num == 6){
					printf("%d", n6);
				} else if (num == 7){
					printf("%d", n7);
				} else if (num == 8){
					printf("%d", n8);
				} else if (num == 9){
					printf("%d", n9);
				} else {
					printf("ERRO");
				}
				
			}
			
		}
	}
	
	
	return 0;
	
}
