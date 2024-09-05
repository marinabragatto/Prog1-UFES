#include <stdio.h>

typedef struct {
	int	id;
	int	lado;
	int numeros[36];
}tCartela;

typedef struct{
	tCartela cartelas[100];
	int qtd;
}tPartida;

void ImprimeCartela(tCartela cartela);
tCartela LeCartela();
tPartida LeCartelasPartida();
void ImprimeInvCartelasPartida(tPartida partida);

int main(){ 
	tPartida partida; 
	partida = LeCartelasPartida(); 
	ImprimeInvCartelasPartida(partida); 
	return 0; 
}

tPartida LeCartelasPartida(){
	tPartida partida;
	int q = 0;
	
	scanf("%d\n", &partida.qtd);
	for (q = 0; q < partida.qtd; q++){
		partida.cartelas[q] = LeCartela();
	}
	return partida;
}

void ImprimeInvCartelasPartida(tPartida partida){
	int q = 0;
	for(q = partida.qtd - 1; q >= 0; q--){
		ImprimeCartela(partida.cartelas[q]);
	}
} 

tCartela LeCartela(){
	tCartela cartela;
	int i = 0;
	scanf("%d %d\n",&cartela.id, &cartela.lado);
	for(i = 0; i < cartela.lado*cartela.lado; i++){
		scanf("%d", &cartela.numeros[i]);
		scanf("%*c");
	}
	return cartela;
}

void ImprimeCartela(tCartela cartela){
	int aux = 0, i = 0, j = 0;

	printf("ID:%d\n", cartela.id);
	for(i = 0; i < cartela.lado; i++){
		for(j = aux; j < (cartela.lado*cartela.lado); j = j + cartela.lado){
			if(j == aux){
				printf("%03d", cartela.numeros[j]);
			}
			else if((j + 1)%cartela.lado == 0){
				printf("|%03d", cartela.numeros[j]);
			}
			else {
				printf("|%03d", cartela.numeros[j]);
			}
		}
		printf("\n");
		aux = aux + 1;
	}
}

 /*tPartida LeCartelasPartida(); Essa fun�o retornar� uma partida com a lista de 
cartelas lidas da entrada padr�o. Ela dever� ler a quantidade de cartelas a serem 
lidas da entrada padr�o e as cartelas em si. 
� void ImprimeInvCartelasPartida(tPartida partida); Essa fun�o receber� uma 
partida como argumento, e imprimir� cada uma das cartelas da partida na ordem 
inversa que foram lidas. */

/*
Entrada: Os dados de uma cartela. Uma cartela � composta por um identificador id 
(inteiro), um tamanho representando a quantidade de linhas e colunas (inteiro < 7), e os 
n�meros inteiros x que compor�o a cartela (1 <= x <= 100). Os n�meros ser�o dados em 
sequ�ncia e devem preencher a tabela de cima para baixo e da esquerda para a direita. 
� Sa�da: A sa�da dever� imprimir a cartela no formato dado nos exemplos abaixo. */
