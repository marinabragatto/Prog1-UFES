#include <stdio.h>

int main (){
	int i = 1, tam = 1, soma = 0, des = 0, tam1 = 0;
	
	scanf("%d", &tam);
	int nota[tam];
	for (i = 0; i < tam; i++){
		scanf("%d", &nota[i]);
	}
		
	
	tam1 = tam - 1;
	if(tam > 1){
		
		if(nota[0] == nota [1]){
			for (i = 2; i < tam; i++){
				if(i == tam1){
					printf("CRESCENTE&DECRESCENTE");
					return 0;
				}
				if(nota [i] == nota [i + 1]){
					continue;
				} else {
					break;
				} 
			}
		}
		
		
		
		if(nota[0] >= nota[1]){
			if(tam > 2){
				for (i = 2; i < tam; i++){
					
					if(i == tam1){
						des = 3;
						break;
					}
					if(nota [i] >= nota [i + 1]){
						continue;
					} 
					else {
						des = 1;
						break;
					}
				}
			} else {
				des = 3; 
			}
		}
		
	

	
		if(nota[0] <= nota[1]){
			if (tam > 2){
				for (i = 2; i < tam; i++){
					if(i == tam1 ){
						des = 2;
						break;
					}
					if(nota [i] <= nota [i + 1]){
						continue;
					} 
					else {
						des = 1;
						break;
					}
				}
			} else {
				des = 2;
			}
		}
	} else if (tam == 1){
		des = 4;
	}
	
	if(des == 1){
		printf("DESORDENADO");
	} 
	else if (des == 2){
		printf("CRESCENTE");
	}
	else if(des == 3){
		printf("DECRESCENTE");
	}
	else if (des == 4){
		printf("CRESCENTE&DECRESCENTE");
	}
	
	
	
	return 0;
	
}
