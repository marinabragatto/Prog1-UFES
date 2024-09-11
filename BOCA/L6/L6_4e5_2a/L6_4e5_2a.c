#include <stdio.h>

typedef struct {
	int	id;
	int	lado;
	int numeros[36];
	
}tCartela;

void ImprimeCartela(tCartela cartela);
tCartela LeCartela();

int main(){ 
	tCartela cartela; 
	cartela = LeCartela(); 
	ImprimeCartela(cartela); 
	return 0; 
} 
tCartela LeCartela(){
	tCartela cartela;
	int i = 0;
	scanf("%d %d\n",&cartela.id, &cartela.lado);
	for(i = 0; i < cartela.lado*cartela.lado; i++){
		scanf("%d", &cartela.numeros[i]);
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


/*
Entrada: Os dados de uma cartela. Uma cartela � composta por um identificador id 
(inteiro), um tamanho representando a quantidade de linhas e colunas (inteiro < 7), e os 
n�meros inteiros x que compor�o a cartela (1 <= x <= 100). Os n�meros ser�o dados em 
sequ�ncia e devem preencher a tabela de cima para baixo e da esquerda para a direita. 
� Sa�da: A sa�da dever� imprimir a cartela no formato dado nos exemplos abaixo. */
