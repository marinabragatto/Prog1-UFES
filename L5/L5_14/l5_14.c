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
int ComparaString(char * str1, char * str2); 
void InicializaLista(int * vet, int qtd);
int VerificaSeEstaNaLista(int * vet, int qtd, int valor);
void ImprimeVetor(int * vet, int qtd){
  int q = 0;
  for (q = 0; q < qtd; q++){
    printf("%d ", vet[q]);
  }
}

int ComparaCandidato(tCandidato c1, tCandidato c2){
//  printf("/%s/  e /%s/", c1.sobrenome, c2.sobrenome);
  if(ComparaString(c1.sobrenome, c2.sobrenome)){
      return 1;
  }
  else{
    return 0;
  }
  
}

int main(){ 
 int qtdCand, i = 0, j = 1, q = -1, res = 0; 

 scanf("%d", &qtdCand); 
  tCandidato candidatos[qtdCand]; 
  int lista[qtdCand];
  InicializaLista(lista, qtdCand);
 // ImprimeVetor(lista, qtdCand);
  

 for(i = 0; i < qtdCand; i++){ 
  candidatos[i] = LeCandidato(); 
 }
for (i = 0; i < qtdCand; i++){
   for (j = 0; j < qtdCand; j++){
    if(j != i){
         if (ComparaCandidato(candidatos[i], candidatos[j])){
          if(!(VerificaSeEstaNaLista(lista, qtdCand, candidatos[i].codigo))){
         //   res = (VerificaSeEstaNaLista(lista, qtdCand, candidatos[i].codigo);
           // printf("%d", res);
            q++;
            lista[q] = candidatos[i].codigo;
           // ImprimeVetor(lista, qtdCand);
            ImprimeCandidato(candidatos[i]);
          }
          if(!(VerificaSeEstaNaLista(lista, qtdCand, candidatos[j].codigo))){

            q++;
            lista[q] = candidatos[j].codigo;
        //   ImprimeVetor(lista, qtdCand);
            ImprimeCandidato(candidatos[j]);
          }
            
         } 
     }
    }
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
int ComparaString(char * str1, char * str2){
  int j = 0, i = 0, res = 0, c = 0;
  for (i = 0; str1[i]; i++);
  for (j = 0; str2[j]; j++);

  if(j != i){
    return 0;
  }
  else{
    for(c = 0; c <= i; c++){
      if(str1[c] != str2[c]){
        return 0;
      }
    }
  }

  return 1;
}

void InicializaLista(int * vet, int qtd){
  int q = 0;
  for (q = 0; q < qtd; q++){
    vet[q] = -1;
  }
}

int VerificaSeEstaNaLista(int * vet, int qtd, int valor){
  int q = 0;
  for (q = 0; q < qtd ; q++){
    if(vet[q] == valor){
      return 1;
    }
    
  }
  return 0;
}