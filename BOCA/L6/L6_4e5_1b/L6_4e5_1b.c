#include <stdio.h>


typedef struct{
	int idm;
	int idp;
	int tam;
	int cde;
	char frase[10];
}tPacote;

tPacote LePacote();
void ImprimePacote(tPacote pac);
int VerificaValidade(tPacote pac);
tPacote InicializaFrase(tPacote pac);


int main(){
	int qtd = 0, q = 1;
	tPacote pac;
	
	scanf("%d\n", &qtd);
	
	for(q = 1; q <= qtd; q++){
		pac = LePacote();
		ImprimePacote(pac);
	}
	
	return 0;
}

tPacote LePacote(){
	tPacote pac;
	char lixo =  'a';
	int t = 1, i = 0;
	
	scanf("%d %d %01d", &pac.idm, &pac.idp, &pac.tam);
	
	pac = InicializaFrase(pac);
	
	for(t = 1, i  = 0; t <= pac.tam; t++, i++){
		scanf("%c", &pac.frase[i]);
	}
	
	if(pac.tam < 9){
		if (pac.tam == 0){
			do{
				scanf("%c", &lixo);
				t++;
			} while (t < 9);
		}
		else {
			do{
				scanf("%c", &lixo);
				t++;
			} while (t <= 9);
		}
	}
	scanf(" %d", &pac.cde);
	return pac;	
}
void ImprimePacote(tPacote pac){
	
	if(VerificaValidade(pac)){
		printf("PCT: %d,%d,%d,%s,%d\n", pac.idm, pac.idp, pac.tam, pac.frase, pac.cde);
	}
	else {
		printf("FALHA!\n");
	}

}
int VerificaValidade(tPacote pac){
	int soma = 0, i = 0;
	
	for (i = 0; i < pac.tam; i++){
		soma =  soma + pac.frase[i];
	}
	
	soma = soma + pac.idm + pac.idp + pac.tam;
	
	if(soma == pac.cde){
		return 1;
	}
	else {
		return 0;
	}
	
	
}
tPacote InicializaFrase(tPacote pac){
	int i = 0;
	
	for (i = 0; i < 10; i++){
		pac.frase[i] = '\0';
	}
	return pac;
}
