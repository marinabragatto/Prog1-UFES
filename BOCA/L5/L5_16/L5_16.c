#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct{ 
 int codigo; 
 char sobrenome[21]; 
 char nome[21]; 
 int nota; 
 int idade; 
} tCandidato; 
 
tCandidato LeCandidato(); 
void ImprimeCandidato(tCandidato candidato); 
void TrocaPosicao(int a , int b, tCandidato * vet);
int EhMelhorColocado(tCandidato analise, tCandidato primeiro);
int MelhorColocado(tCandidato * vet, int a, int qtd);
void OrdenaCrescente(tCandidato * vet, int qtd); 
 
int main(){ 
 int qtdCand, i = 0, j; 
  
 scanf("%d", &qtdCand); 
  tCandidato candidatos[qtdCand]; 
  
 for(i = 0; i < qtdCand; i++){ 
  candidatos[i] = LeCandidato(); 
 } 
 
 OrdenaCrescente(candidatos, qtdCand); 
  
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


void OrdenaCrescente(tCandidato * vet, int qtd){
	int idx = 0, i = 0;
	
	for(i = 0; i < qtd - 1 ; i++){
		idx = MelhorColocado(vet, i + 1, qtd);
		if(EhMelhorColocado(vet[idx], vet[i])){
			TrocaPosicao(idx, i, vet);
		}
	}
}

int EhMelhorColocado(tCandidato analise, tCandidato primeiro){
	
	if(analise.nota > primeiro.nota){
		return 1;
	}
	if (analise.nota == primeiro.nota){
		if(primeiro.idade > analise.idade){
			return 1;
		}
	} 
	if(analise.idade == primeiro.idade){
		if(primeiro.codigo > analise.codigo){
			return 1;
		}
	}
	return 0;	
	
}

int MelhorColocado(tCandidato * vet, int a, int qtd){
	int idx = 0, i = 0;
	tCandidato melhor;

	melhor = vet[a];
	idx = a;
	
	for(i = a + 1; i < qtd; i++){
		if(EhMelhorColocado(vet[i], melhor)){
			melhor = vet[i];
			idx = i;
		}
	}
	
	return idx;
}

void TrocaPosicao(int a , int b, tCandidato * vet){
	tCandidato aux;
	aux = vet[a];
	vet[a] = vet[b];	
	vet[b] =  aux;
}
