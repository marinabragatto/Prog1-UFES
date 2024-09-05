#include <stdio.h>

void InverteVetor(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main(){
	int qtd = 0, q = 0;
	
	scanf("%d", &qtd);
	if(qtd == 0){
		printf("{}");
		return 0;
	}
	
	int n[qtd];
	
	for (q = 0; q < qtd ; q++){
		scanf("%d", &n[q]);
	}
	InverteVetor(n, qtd);
	ImprimeDadosDoVetor(n, qtd);
	return 0;
}

void InverteVetor(int vet[], int qtd){
	int q = 0, j = 0, aux = 0;
	for (q = 0, j = qtd - 1; q < qtd/2; q++, j--){
		aux = vet[q];
		vet[q] = vet[j];
		vet[j] = aux;
	}
}
void ImprimeDadosDoVetor(int vet[], int qtd){
	int q = 0;
	printf("{");
	for (q = 0; q < qtd ; q++){
		if(q == qtd - 1){
			printf("%d}", vet[q]);
		} 
		else {
			printf("%d, ", vet[q]);
		}
		
		
	}
}
