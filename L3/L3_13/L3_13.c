#include <stdio.h>

int NaoEhLetra (char c);
int CalculaValorPalavra();
int EhPrimo(int n);
int CalculaLetra(char c);
int ProximoPrimo(int n);

int main(){
	int ret = 0,i =1, valor = 1, prox = 1;
	
	while(i){
		valor = CalculaValorPalavra();
	
		if (valor == 0){
			break;
		}

		if(EhPrimo(valor)){
			printf("E primo\n");
		} else {
			printf("Nao e primo ");
			prox = ProximoPrimo(valor);
			printf("%d\n", prox);
		}
	}
	
	return 0;
	
}

int NaoEhLetra (char c){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
		return 0;
	}
	else {
		return 1;
	}
}

int CalculaValorPalavra(){
	int soma = 0, valor = 1, i = 1, ret = 1, prox = 1;
	char c = 'a';
	
	while(i){
    	ret = scanf("%c", &c);
		if(ret != 0 && ret != -1){
			if(NaoEhLetra(c)){
				break;
			}
			else {
				valor = CalculaLetra(c);
				soma = soma + valor;
			}
			
		} else {
			return 0;
		}
	}
	return soma;
}

int CalculaLetra(char c){
	if(c >= 'a' && c <= 'z'){
		c = c - 96;
	} 
	else if(c >= 'A' && c <= 'Z'){
		c = c - 38;
	}
	return c;
}

int EhPrimo(int n){
	int den = 2, resto = 1;
	
	if(n == 2){
		return 1;
	}
	else if(n == 0) {
		return 0;
	}
	
	for(den = 2; den < n ; den++){
		resto = n%den;
		if(resto == 0){
			return 0;
		}
	}
	return 1;
}
int ProximoPrimo(int n){
	int i = 0, j = 1;
	for(i = n ; j ;i++){
		if(EhPrimo(i)){
			return i;
		}
	}
}

//Problema: Voc� deve ler uma s�rie de palavras, onde cada palavra � 
//composta somente por letras no intervalo a-z e A-Z. Cada letra possui um valor 
//espec�fico, a letra 'a' vale 1, a letra 'b' vale 2 e assim por diante, at� a letra 'z', que 
//vale 26. Do mesmo modo, a letra 'A' vale 27, a letra 'B' vale 28 e a letra 'Z' vale 52. O 
//valor da palavra � soma dos valores das letras.  Voc� deve escrever um programa 
//para determinar se uma palavra � uma palavra prima ou n�o. Caso ela n�o seja 
//prima, voc� dever� indicar o pr�ximo n�mero �quela palavra que � primo.  


//a) Seu programa deve conter a fun��o int CalculaValorPalavra(); que retorna o 
//n�mero representando a palavra ap�s a soma dos valores de suas letras, ou zero 
//caso n�o seja letra. 
//b) Seu programa deve conter a fun��o int EhPrimo(int n); que retorna verdadeiro se o 
//n�mero n for primo ou falso caso contr�rio.  
//c) Seu programa deve conter a fun��o int ProximoPrimo(int n); que retorna o pr�ximo 
//primo ap�s n.
