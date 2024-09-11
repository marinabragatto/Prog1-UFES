#include <stdio.h>

int main (){
	int max = 0, inicio = 0, ini = 0, l = 0, laterais = 0, intt = 0; 
	
	scanf("%d %d", &inicio, &max);
	(max - inicio)/2;
	
	
	for (ini = inicio; ini <= max; ini = ini + 2){
		laterais = (max - ini)/2;
		for (l = 1 ; l <= laterais; l++ ){
			printf("_");
		} 
		for(intt = 1; intt <= ini; intt++){
			printf("$");
		}
		for (l = 1 ; l <= laterais; l++ ){
			printf("_");
		}
		printf("\n");
	}
	
	for (ini = max - 2; ini >= 1 ;ini = ini - 2){
		laterais = (max - ini)/2;
		for (l = 1 ; l <= laterais; l++ ){
			printf("_");
		} 
		for(intt = 1; intt <= ini; intt++){
			printf("$");
		}
		for (l = 1 ; l <= laterais; l++){
			printf("_");
		}
		printf("\n");
	}
	
	
}
