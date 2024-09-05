#include <stdio.h>
#include <math.h>

int main (){
	int n = 0, i = 0, j = 0, x = 2; 
	
	scanf ("%d",&n);
	
	for (i = 2; i < n; i++){
		j = n%i;
		if (j == 0){
			printf("Nao primo");
			x = 3;
			i = i + (2*n);
		}	
	}
	if (x == 2 && n != 1){
	printf("Primo");
	} else if (n == 1){
		printf("Nao primo");
	}
	return 0;
}
	

