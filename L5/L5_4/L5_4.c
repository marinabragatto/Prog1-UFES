#include <stdio.h>

int main (){
	int i = 1, qtd = 0, q = 0, a = 0, b = 0, den = 0, fora = 0;
	
	scanf("%d", &qtd);
	
	int n[qtd - 1];
	
	for (q = 0; q < qtd; q++){
		scanf("%d", &n[q]);
	}
	
	scanf("%d %d", &a, &b);
	
	for(q = 0; q < qtd; q++){
		if(n[q] >= a && n[q] <= b){
			den++;
		}
		else {
			fora++;
		}
	}
	
	printf("%d %d", den, fora);
	return 0;
}
