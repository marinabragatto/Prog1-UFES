#include <stdio.h>

void InicializaMatriz(int lin , int col, int m[lin][col]);
void PrintaMatriz(int lin, int col, int m[lin][col]);
void SeMovimenta(int lin, int col, int m[lin][col], int x, int y, int posX, int posY);
int RetornaModulo(int x);

int main(){
	int col = 0, lin = 0, posX = 0, posY = 0, x = 0, y  = 0;

	scanf("%d %d", &col, &lin);
	
	int m[lin][col];
	
	InicializaMatriz(lin , col, m);
//	PrintaMatriz(lin, col, m);
	
	while(1){
		scanf("%d %d", &x, &y);
		SeMovimenta(lin, col, m, x , y, posX, posY);
	//	printf("passei\n");
		
		posX = x;
		posY = y;
		if(x == 0 && y == 0){
			break;
		}
		
	}
	PrintaMatriz(lin, col, m);
		
	return 0;
}

void InicializaMatriz(int lin , int col, int m[lin][col]){
	int i = 0, j = 0;
	for (i = 0; i < lin; i++){
		for ( j = 0; j < col; j ++){
			if(i == 0 && j == 0){
				m[i][j] = 1;
			}
			else {
				m[i][j] = 0;
			}
		}
	}
}

void PrintaMatriz(int lin, int col, int m[lin][col]){
	int i = 0, j = 0;
	for (i = 0; i < lin; i++){
		for ( j = 0; j < col; j ++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
}

void SeMovimenta(int lin, int col, int m[lin][col], int x, int y, int posX, int posY){
	int hor = 0, ver = 0;
	while(1){
		if(posX == x  && posY == y){
			m[posY][posX] = 1;
			break;
		}
		
		hor = RetornaModulo(posX - x);
		ver = RetornaModulo(posY - y);
		//printf("%d %d", hor, ver);
		//break;
		
	//	printf("%d %d", posX , ver);
		
		if((hor <= ver && hor != 0) || (ver == 0 && hor != 0)){
			if(posX > x){
				while(posX != x){
					posX--;
					m[posY][posX] = 1;
				}
			}
			else if(posX < x){
				while(posX != x){
					posX++;
					m[posY][posX] = 1;
				}
			}
		}
		else {
			if(posY > y){
				while(posY != y){
					posY--;
					m[posY][posX] = 1;
				}
			}
			else if(posY < y){
				while(posY != y){
					posY++;
					m[posY][posX] = 1;
				}
				//printf("\n pos y %d y %d posx %d x %d \n", posY, y, posX, x);
				//break;
			}
			
		}
	}
	
}

int RetornaModulo(int x){
	if(x < 0){
		return -x;
	}
	else {
		return x;
	}
}
