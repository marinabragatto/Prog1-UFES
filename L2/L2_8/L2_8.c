#include <stdio.h>
#include <math.h>

int main (){
	int n = 0, i = 0, j = 0, x = 2, inicio = 0, final = 0, k = 1; 
	
	scanf ("%d %d",&inicio, &final);
	printf("RESP:");
	
	for (inicio++ ;  inicio < final ; inicio++ ){
		
		for (i = 2; i < inicio; i++){
			j = inicio%i;
			if (j == 0){
				x = 3;
				i = i + (2*final);
			
			}
		}
		if (x == 2 && inicio != 1){
			printf("%d ", inicio);
		}
		x = 2;
		
		
	}	
	return 0;
}
	

