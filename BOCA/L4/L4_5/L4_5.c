#include <stdio.h>
#include <math.h>

typedef struct {
	
	int y;
	int x;
		
} tPonto;

tPonto IniciarV();
tPonto LePonto();
float CalculaDist(tPonto atual, tPonto ant);

int main (){
	int qtd = 0, q = 1;
	float dist = 0;
	tPonto ant, atual;
	ant = IniciarV();
	atual = IniciarV();
	
	scanf("%d", &qtd );
	
	ant = LePonto();
	printf("-\n");
	qtd--;
	
	for(q = 1; q <= qtd; q++){
		atual = LePonto();
		dist = CalculaDist(atual, ant);
		printf("%.2f\n", dist);
		ant = atual;
	}
}

tPonto IniciarV(){
	tPonto p;
	p.x = 2;
	p.y = 2;
	return p;
}
tPonto LePonto(){
	tPonto p;
	scanf("%d %d",&p.x, &p.y);
	return p;
}

float CalculaDist(tPonto atual, tPonto ant){
	float dis = 0, deltaX = 0, deltaY = 0;
	
	deltaX = atual.x - ant.x;
	deltaY = atual.y - ant.y;
	
	dis = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

	return dis;
}
