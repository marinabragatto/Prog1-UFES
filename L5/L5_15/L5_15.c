#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
 
typedef struct{ 
	int codigo; 
 	char sobrenome[21]; 
 	char nome[21]; 
 	int nota; 
 	int idade; 
} tCandidato; 
 
tCandidato LeCandidato(); 
void ImprimeCandidato(tCandidato candidato); 
void TrocaVetAeB(tCandidato vet[], int idx, int i);
void OrdenaCrescenteCand(tCandidato * vet, int qtd);
int MenorValorAeB(tCandidato vet[], int a, int b, int c);


 
int main(){ 
	int qtdCand = 0, i = 0, j = 1, q = -1, res = 0; 

	scanf("%d", &qtdCand); 
	tCandidato candidatos[qtdCand]; 

	 for(i = 0; i < qtdCand; i++){ 
		candidatos[i] = LeCandidato(); 
	 }
 	
	OrdenaCrescenteCand(candidatos, qtdCand); 
  
 	for(i = 0; i < qtdCand; i++){ 
  		ImprimeCandidato(candidatos[i]); 
 	} 
  
    return 0;     
} 

 
tCandidato LeCandidato(){ 
 tCandidato candidato; 
 scanf("%*[^{]"); 
 scanf("%*[{ ]"); 
 scanf("%d", &candidato.codigo); 
 scanf("%*[, ]"); 
 scanf("%[^,],", candidato.sobrenome); 
 scanf("%*[ ]"); 
 scanf("%[^,],", candidato.nome); 
 scanf("%d", &candidato.nota); 
 scanf("%*[, ]"); 
 scanf("%d", &candidato.idade); 
 scanf("%*[^\n]\n");
 return candidato; 
}
 
void ImprimeCandidato(tCandidato candidato){ 
 	printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",  
  	 	candidato.codigo, candidato.nome,  
 		candidato.sobrenome, candidato.nota, candidato.idade); 
} 

void TrocaVetAeB(tCandidato vet[], int idx, int i){
	tCandidato aux;
	aux = vet[idx];
	vet[idx] = vet[i];
	vet[i] = aux;
}

void OrdenaCrescenteCand(tCandidato * vet, int qtd){
	int idx = 0, q = 0, i = 0, j = 0, in = 0, is = 0;

	for(j = 0; j < qtd - 1; j++){
		in = MenorValorAeB(vet, j + 1, qtd - 1, -1);
		
		if((strcmp(vet[j].nome, vet[in].nome)) > 0){
			TrocaVetAeB(vet, j, in);
		}
		else if((strcmp(vet[j].sobrenome, vet[in].sobrenome) > 0) && ((strcmp(vet[j].nome, vet[in].nome)) == 0)){
			TrocaVetAeB(vet, j, in);
		}
	}
}

int MenorValorAeB(tCandidato vet[], int a, int b, int c){
	int i = 0, idx = 0, x = 0;
	char menor[21], menor2[21];
	for(x = 0; vet[a].nome[x] ; x++){
		menor[x] = vet[a].nome[x];
	}
	for(x = 0; vet[a].nome[x] ; x++){
		menor2[x] = vet[a].sobrenome[x];
	}

	idx = a;


	for(i = a + 1; i <= b; i++){
		if(strcmp(menor, vet[i].nome) > 0){
			for(x = 0; menor[x]; x++){
					menor[x] = 0;
			}
			for(x = 0; menor2[x]; x++){
				menor2[x] = 0;
			}
			for(x = 0; vet[i].nome[x] ; x++){
				menor[x] = vet[i].nome[x];
			}
			for(x = 0; vet[i].sobrenome[x]; x++){
					menor2[x] = vet[i].sobrenome[x];
			}
			idx = i;
		} 
		else if(strcmp(menor, vet[i].nome) == 0){
			if(strcmp(menor2, vet[i].sobrenome) > 0){
				for(x = 0; menor[x]; x++){
					menor[x] = 0;
				}
				for(x = 0; menor2[x]; x++){
					menor2[x] = 0;
				}
				for(x = 0; vet[i].nome[x]; x++){
					menor[x] = vet[i].nome[x];
				}
				for(x = 0; vet[i].sobrenome[x]; x++){
					menor2[x] = vet[i].sobrenome[x];
				}
				idx = i;		
			}
		}	
	}

	return idx;
}
