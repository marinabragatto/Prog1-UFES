#include <stdio.h>

void TrocaParEImpar(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);
int EhPar(int n);

int main(){
	int qtd = 0, q = 0;
	
	scanf("%d", &qtd);
	if (qtd == 0){
		printf("{}");
		return 0;
	}
	
	int n[qtd];
	
	for (q = 0; q < qtd ; q++){
		scanf("%d", &n[q]);
	}
	TrocaParEImpar(n, qtd);
	ImprimeDadosDoVetor(n, qtd);
	
	return 0;
}

void TrocaParEImpar(int vet[], int qtd){
	int q = 0, aux = 0;
	for (q = 0; q < qtd ; q++){
		if (!(EhPar(q + 1))){
			if(q != qtd - 1){
				aux = vet[q];
				vet[q] = vet[q + 1];
				vet[q + 1] = aux;
			}		
		}
	}

}
void ImprimeDadosDoVetor(int vet[], int qtd){
	int q = 0;
	printf("{");
	for (q = 0; q < qtd; q++){
		if (q == qtd - 1){
			printf("%d}",vet[q]);
		}
		else {
			printf("%d, ", vet[q]);
		}	
	}
	
}

int EhPar(int n){
	int resto = 0;
	resto = n%2;
	if(resto == 0){
		return 1;
	}
	else {
		return 0;
	}
}
