#include <stdio.h>

void OrdenaCrescente(int vet[], int qtd); 
void ImprimeDadosDoVetor(int vet[], int qtd);
int MenorValorAeB(int vet[], int a, int b);
int EhMenor(int menor, int a);
void TrocaVetAeB(int vet[], int idx, int i);

int main(){
	int qtd = 0, q = 0;
	
	scanf("%d", &qtd);
	if (qtd == 0){
		printf("{}");
		return 0;
	}
	
	int n[qtd];
	
	for (q = 0; q < qtd; q++){
		scanf("%d", &n[q]);
	}
	
	OrdenaCrescente(n, qtd);
	ImprimeDadosDoVetor(n, qtd);
	
	return 0;
}

void OrdenaCrescente(int vet[], int qtd){
	int idx = 0, q = 0, i = 0;
	
	
	for (q = 0; q < qtd - 1; q++){
		i = MenorValorAeB(vet, q + 1, qtd - 1);
		if(EhMenor(vet[q], vet[i])){
			TrocaVetAeB(vet, q, i);
		}
	}
}

void TrocaVetAeB(int vet[], int idx, int i){
	int aux = 0;
	aux = vet[idx];
	vet[idx] = vet[i];
	vet[i] = aux;
}

int EhMenor(int menor, int a){
	return a < menor;
}

int MenorValorAeB(int vet[], int a, int b){
	int i = 0, idx = 0, menor = 0;
	
	menor = vet[a];
	idx = a;
	
	for(i = a + 1; i <= b; i++){
		if(EhMenor(menor, vet[i])){
			menor = vet[i];
			idx = i;
		}
	}
	
	return idx;
}

void ImprimeDadosDoVetor(int vet[], int qtd){
	int i = 0;
	printf("{");
	for (i = 0; i < qtd; i++){
		if(i == qtd - 1){
			printf("%d}", vet[i]);
		}
		else {
			printf("%d, ", vet[i]);
		}
		
	}
}
