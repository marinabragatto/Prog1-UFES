#include <stdio.h>
#include <math.h>
#define const 6

int main(){

	int i = 1, n = 2;
	float z = 0, soma = 0, y = 0, k = 1;
	
	scanf("%d", &n);
	
	for (i = 1; i<=n ; i++){
	
	 y = const/(k*k);
	 soma = soma + y;
	 z = sqrt (soma);
	 if (n==i){
	   printf("%.6f \n", z);
	}
	
	 k++;
	}
	return 0;
}
