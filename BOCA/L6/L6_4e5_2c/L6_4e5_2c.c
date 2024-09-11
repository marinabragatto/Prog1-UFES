#include <stdio.h>

typedef struct {
	int	id;
	int	lado;
	int numeros[2][49];
}tCartela;

typedef struct{
	tCartela cartelas[100];
	int qtdCar;
	int sorteado;
	int vencedor;
}tPartida;

void ImprimeCartela(tCartela cartela);
tCartela LeCartela();
tPartida LeCartelasPartida();
tCartela MarcaCartela(tCartela cartela, int sorteado);
void JogarPartida(tPartida partida);
tPartida ResetaPartida(tPartida partida);
tCartela ResetaCartela(tCartela cartela);
int VenceuCartela(tCartela cartela);

int main(){ 
	tPartida partida; 
	int qtdPartidas = 0, i = 0, j = 0; 
	
	partida = LeCartelasPartida(); 
	scanf ("%d", &qtdPartidas); 
	
	for (i = 0; i < qtdPartidas; i++){ 
		if ( i!=0 ) printf("\n"); 
		printf("PARTIDA %d\n", i+1); 
		
		partida = ResetaPartida(partida); 
		
		JogarPartida(partida); 
	} 
	return 0; 
}

tPartida LeCartelasPartida(){
	tPartida partida;
	int q = 0;
	
	scanf("%d\n", &partida.qtdCar);
	for (q = 0; q < partida.qtdCar; q++){
		partida.cartelas[q] = LeCartela();
	}
	return partida;
}



tCartela LeCartela(){
	tCartela cartela;
	int i = 0;
	scanf("%d %d\n",&cartela.id, &cartela.lado);
	for(i = 0; i < cartela.lado*cartela.lado; i++){
		scanf("%d", &cartela.numeros[0][i]);
	}
	scanf("%*[^\n]");
	return cartela;
}

void ImprimeCartela(tCartela cartela){
	int aux = 0, i = 0, j = 0;

	printf("ID:%d\n", cartela.id);
	for(i = 0; i < cartela.lado; i++){
		for(j = aux; j < (cartela.lado*cartela.lado); j = j + cartela.lado){
			if(j == aux){
				printf("%03d", cartela.numeros[0][j]);
			}
			else if((j + 1)%cartela.lado == 0){
				printf("|%03d", cartela.numeros[0][j]);
			}
			else {
				printf("|%03d", cartela.numeros[0][j]);
			}
		}
		printf("\n");
		aux = aux + 1;
	}
}

void JogarPartida(tPartida partida){
	int i = 0, j = 0;
	int qtdVencedores = 0, temWinner = 0;

	while(1){
		if(temWinner == 1){
			while(1){
				scanf("%d", &partida.sorteado);
				if(partida.sorteado == -1){
					break;
				}
			}
		}
		else {
			scanf("%d", &partida.sorteado);
		}
		
		if(partida.sorteado == -1){
			break;
		}
		for(i = 0; i < partida.qtdCar; i++){
			partida.cartelas[i] = MarcaCartela(partida.cartelas[i], partida.sorteado);
		}
		for (i = 0; i < partida.qtdCar; i++){
			if(VenceuCartela(partida.cartelas[i])){
				temWinner = 1;
				break;
			}
		}
	}
	
	for (i = 0; i < partida.qtdCar; i++){
		if(VenceuCartela(partida.cartelas[i])){
			qtdVencedores++;
			if(qtdVencedores == 1){
				printf("COM VENCEDOR\n");
			}
			ImprimeCartela(partida.cartelas[i]);
		}
	}

	if (qtdVencedores == 0) {
		printf("SEM VENCEDOR\n");
	}

}

tCartela MarcaCartela(tCartela cartela, int sorteado){
	int i = 0;
	for (i = 0; i < cartela.lado*cartela.lado; i++){
		if(cartela.numeros[0][i] == sorteado){
			cartela.numeros[1][i] = 1;
		}
	}
	return cartela;
}

tPartida ResetaPartida(tPartida partida){
	int i = 0;

	for (i = 0; i < partida.qtdCar; i++){
		partida.cartelas[i] = ResetaCartela(partida.cartelas[i]);
	}
	return partida;
}

tCartela ResetaCartela(tCartela cartela){
	int i = 0;
	for(i = 0; i < (cartela.lado*cartela.lado) ; i++){
		cartela.numeros[1][i] = 0;
	}
	return cartela;
}

int VenceuCartela(tCartela cartela){
	int i = 0;
	for (i = 0; i < (cartela.lado*cartela.lado); i++){
		if(cartela.numeros[1][i] == 0){
			return 0;
		} 
	}
	return 1;
}


