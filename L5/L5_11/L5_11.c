#include <stdio.h>

void OrdenaCrescente(int vet[], int qtd); 
void ImprimeDadosDoVetor(int vet[], int qtd);
int MenorValorAeB(int vet[], int a, int b);
int EhMenor(int menor, int a);
void TrocaVetAeB(int vet[], int idx, int i);
void OrdenaOfinal(int vet1[], int vet2[], int vet3[], int qtd1, int qtd2, int qtd3);

int main(){
	int qtd1 = 0, qtd2 = 0, q = 0, qtd3 = 0, j = 0;
	
	scanf("%d", &qtd1);

	
	int n1[qtd1];
	
	for (q = 0; q < qtd1; q++){
		scanf("%d", &n1[q]);
	}
	
	scanf("%d", &qtd2);

	
	int n2[qtd2];
	
	for (q = 0; q < qtd2; q++){
		scanf("%d", &n2[q]);
	}
	
	
	OrdenaCrescente(n1, qtd1);
	OrdenaCrescente(n2, qtd2);
	
//	ImprimeDadosDoVetor(n1, qtd1);
//	ImprimeDadosDoVetor(n2, qtd2);
	
	qtd3 = qtd2 + qtd1;
	
	int n3[qtd3];
	
	for(q = 0; q < qtd1; q++){
		n3[q] = n1[q];
	}
	
//	printf("%d", qtd1);
	
	for (q = qtd1, j = 0;  q < qtd3; q++, j++){
		n3[q] = n2[j];
	}
	
	OrdenaOfinal(n1, n2, n3, qtd1, qtd2, qtd3);
	
//	ImprimeDadosDoVetor(n3, qtd3);
		
	
	return 0;
}

void OrdenaOfinal(int vet1[], int vet2[], int vet3[], int qtd1, int qtd2, int qtd3){
	int idx = 0, q = 0, i = 0, j = 0, z = 0, a = 0, b = 0, k = 0;
	
	for (q = 0; q < qtd3 - 1; q++){
		i = MenorValorAeB(vet3, q + 1, qtd3 - 1);
		if(EhMenor(vet3[q], vet3[i])){
			TrocaVetAeB(vet3, q, i);
		}
	}
//	printf("%d", qtd3);
	for(q  = 0; q < qtd3; q++){
		for(j = 0, a = 0; j < qtd1 ; j++ ){
			if(vet3[q] == vet1[j]){
				a++;
			}
		}
		for(j = 0, b = 0; j < qtd2 ; j++ ){
			if(vet3[q] == vet2[j]){
				b++;
			}
		}
		if (a >= 1 && b == 0){
			printf("A");
		}	
		else if(a == 0 && b >= 1){
			printf("B");
		}
		else if(a == 1 && b == 1 && z == 0){
			printf("A");
			z++;
		}
		else if(a == 1 && b >= 1 && z == 1){
			printf("B");
			z = 0;
		}
		else if((a > 1 && b > 1) || (a >= 1 && b == 1) || (a == 1 && b >= 1)){
			if(k < a){
				printf("A");
			}
			
			if(k >= a){
				printf("B");
			}
			if (k == a + b){
				k = 0;	
			}
			k++;
		}
	}

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
