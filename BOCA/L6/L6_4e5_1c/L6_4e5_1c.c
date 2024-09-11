#include <stdio.h>

typedef struct{
	int idm;
	int idp;
	int tam;
	int cde;
	char frase[10];
}tPacote;

typedef struct {
	tPacote pacs[100];
	
}tMensagens;




tPacote LePacote();
int TamanhoIdmEhDif(tPacote p1, tPacote p2);
tMensagens OrdenaIdpDeAateB(tMensagens msg, int q2at , int q2);
tMensagens TrocaVetAeB(tMensagens msg, int idx, int i);
void ImprimeMensagens(tMensagens msg, int qtd);
tMensagens OrdenaIdm(tMensagens msg, int qtd);
int VerificaValidade(tPacote pac);
tPacote InicializaFrase(tPacote pac);
tMensagens LeMensagens(int qtd);
int MenorValorEntreAeB(int a, int b, tMensagens msg, int cod);
int EhMenorIdmUmDoQeDois(tPacote pac1, tPacote menor, int cod);
int QtdDeMsgs(tMensagens msg, int qtd);
void ImprimeFrase(tPacote pac);

int main(){
	int qtd = 0, q = 1;
	tMensagens msg;
	tPacote pac;
	
	scanf("%d\n", &qtd);
	
	msg = LeMensagens(qtd);
	ImprimeMensagens(msg, qtd);
	
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

int TamanhoIdmEhDif(tPacote p1, tPacote p2){
	if(p1.idm != p2.idm){
		return 1;
	}
	else {
		return 0;
	}

	
}

int QtdDeMsgs(tMensagens msg, int qtd){
	int n = 0, i = 0;

	for(i = 0; i < qtd; i++){
		if(TamanhoIdmEhDif(msg.pacs[i], msg.pacs[i + 1])){
			n++;
		}
	}
	return n;
}

tPacote InicializaFrase(tPacote pac){
	int i = 0;
	
	for (i = 0; i < 10; i++){
		pac.frase[i] = '\0';
	}
	return pac;
}

tMensagens LeMensagens(int qtd){
	tMensagens msg;
	int q = 1, i = 0;
	for(q = 1, i = 0; q <= qtd; q++, i++){
		msg.pacs[i] = LePacote();
	}
	return msg;
}

void ImprimeFrase(tPacote pac){
	printf("%s", pac.frase);
}

void ImprimeMensagens(tMensagens msg, int qtd){
	int i = 0, q = 0, k = 0, q2 = 0, imp = 1, q2at = 0, j = 0;

	msg = OrdenaIdm(msg, qtd);
	
	q = QtdDeMsgs(msg, qtd);

	
	for(imp = 1; imp <= q; imp++){
		q2at = q2;
		for(i = q2 ; i < qtd; i++, q2++){
			if(TamanhoIdmEhDif(msg.pacs[i], msg.pacs[i+1])){
				q2++;
				break;
			}
		}
	
		msg = OrdenaIdpDeAateB(msg, q2at, q2 );
		
		for (j = q2at; j < q2; j++){
			if(VerificaValidade(msg.pacs[j])){
				ImprimeFrase(msg.pacs[j]);
			}
			else {
				printf("##FALHA##");
			}
		
		}
		if(imp != q){
			printf("\n");
		}
		
	}
		
	
}

tMensagens OrdenaIdpDeAateB(tMensagens msg, int q2at , int q2){
	int i = 0, idx = 0;

		for(i = q2at; i < q2 - 1; i++){
			idx = MenorValorEntreAeB(i + 1, q2, msg, 2);
			if(EhMenorIdmUmDoQeDois(msg.pacs[idx], msg.pacs[i], 2)){
				msg = TrocaVetAeB(msg, idx, i);
			}	
		}
	
	return msg;
}


tMensagens  TrocaVetAeB(tMensagens msg, int idx, int i){
	tPacote aux;
	
	aux = msg.pacs[idx];
	msg.pacs[idx] = msg.pacs[i];
	msg.pacs[i] = aux;
	return msg;
}



tMensagens OrdenaIdm(tMensagens msg, int qtd){
	int idx = 0, i = 0;
	
	
	for(i = 0; i < qtd - 1; i++){
		idx = MenorValorEntreAeB(i + 1, qtd, msg, 1);
		if(EhMenorIdmUmDoQeDois(msg.pacs[idx], msg.pacs[i], 1)){
			msg = TrocaVetAeB(msg, idx, i);
		}	
	}
	return msg;
}

int MenorValorEntreAeB(int a, int b, tMensagens msg, int cod){
	tPacote menor;
	int idx = 0, i = 0;
	
	menor = msg.pacs[a];
	idx = a;
	if(cod == 2){
		for (i = a + 1; i < b; i++){
			if(EhMenorIdmUmDoQeDois(msg.pacs[i], menor, 2)){
				menor = msg.pacs[i];
				idx = i;
			}
		}
	}
	else if(cod == 1){
		for (i = a + 1; i < b; i++){
			if(EhMenorIdmUmDoQeDois(msg.pacs[i], menor, 1)){
				menor = msg.pacs[i];
				idx = i;
			}
		}
	}
		
	return idx;
}

int EhMenorIdmUmDoQeDois(tPacote pac1, tPacote menor, int cod){
	if(cod == 1){
		if(pac1.idm < menor.idm){
			return 1;
		}
		else {
			return 0;
		}
	
	}
	if(cod == 2){
		if(pac1.idp < menor.idp){
			return 1;
		}
		else {
			return 0;
		}
	
	}	
}
/*
Assumir que tMensagens só precisa armazenar
no máximo 100 pacotes. Incrementar o tipo tPacote da questão anterior conforme
necessário. O programa principal só deve acessar as mensagens pelas funções que
manipulam tMensagens. As funções de tMensagens só deve acessar os pacotes via
funções que manipulam tPacotes.*/

