#include <stdio.h>

void LeMatriz(int l, int c, int m[l][c]);
void MultpEImprime(int l1, int c1, int m1[l1][c1], int l2, int c2, int m2[l2][c2]);

int main(){
	int qtd = 0, i = 0, l1 = 0, l2 = 0, j = 0, c1 = 0, c2 = 0, q = 0;
	
	scanf("%d", &qtd);
	
	for(q = 1; q <= qtd; q++){
		scanf("%d %d", &c1, &l1);
		int m1[l1][c1];
		LeMatriz(l1 , c1, m1);
		scanf("%d %d", &c2, &l2);
		int m2[l2][c2];
		LeMatriz(l2, c2, m2);
		MultpEImprime(l1, c1, m1, l2 , c2, m2);
	}
	return 0;
}

void LeMatriz(int l, int c, int m[l][c]){
	int i = 0, j = 0;
	
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			scanf("%d", &m[i][j]);
		}
	}
}

void MultpEImprime(int l1, int c1, int m1[l1][c1], int l2, int c2, int m2[l2][c2]){
	int i = 0, j = 0, produto = 0, geral = 0, n = 0;

	if(c1 == l2){
		geral = c1;
		int m3[l1][c2];
		for(i = 0; i < l1; i++){
			for(j = 0; j < c2; j++){
				for(n = 0; n < geral; n++){
					produto += m1[i][n] * m2[n][j];
				
				}
				printf("%d", produto);
				produto = 0;
				if(j != c2 - 1){
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	else{
		printf("IMPOSSIVEL\n");
	}
	printf("\n");
	
}
