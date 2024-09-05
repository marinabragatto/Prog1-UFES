#include <stdio.h>
#include <math.h>


int main(){
	
	int l = 0, c = 0, i = 0, j = 0;
	int soma = 0, atual = 0, total = 0;

	scanf("%d %d", &l, &c);



	for (j = 1; j<=l; j++){
		for(i = 1; i<=c; i++){
			scanf("%d", &atual);
			soma = soma + atual;
		}
		printf("%d\n", soma);
		total = total + soma;
		soma = 0;
	}
	
	
	
	
	printf("%d\n", total);

	return 0;
}
