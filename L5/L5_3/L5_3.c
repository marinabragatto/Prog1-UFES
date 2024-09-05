#include <stdio.h>

int Modulo(int n);

int main(){
	int i = 1, qtd = 1, soma = 0, des = 0, j = -1, m = -1, control = 1, n = -1, maior = 0, k = 1, x = 0;
	
	scanf("%d", &qtd);
//	printf("qtd %d qtd", qtd);
	if(qtd == 1){
		printf("IMPOSSIVEL");
		return 0;
	}
	
	int h[qtd], delta[qtd], p1[qtd], p2[qtd];
	
	for (i = 0, control = 1, j = -1, m = -1, n = -1; i < qtd; control++, j++, i++, n++, m++){
		scanf("%d", &h[i]);
	//	printf("n == %d altura == %d\n", i, h[i]);
		if(control >= 2){
			delta[j] = h[i] - h[i - 1];
			delta[j] = Modulo(delta[j]);
		//	printf("DELTA == %d\n", delta[j]);
			if(delta[j] >= maior || k == 1){
				k++;
				maior = delta[j];
		//		printf("MAIOR == %d", maior);
				p1[m] = i;
				p2[n] = i - 1;
			}
		}
	}
	
	for (x = 0; x < qtd; x++){
		if(delta[x] == maior){
			printf(" (%d %d)", p2[x], p1[x]);
		}
		
	}
	
	return 0;
	
}

int Modulo(int n){
	if(n < 0){
		n = -n;
	}
	return n;
}


