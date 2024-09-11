#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int n = 1, max = 0, soma = 0, i = 0;
	float div = 0, media =0; 
	
	while (n != 0){
		scanf("%d", &n);
		soma = soma + n;
		div++;
		media = soma/div;
		if(n>=max || max == 0){
			max = n;
		}
		if(n != 0) {
			printf("%d %.6f \n", max, media);
		}
	}
	
	return 0;
	exit;
}
