#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
	
}tPonto;

tPonto IniciarV();
tPonto LePonto();
void ImprimePnt(tPonto p);
tPonto MovXeYSim(tPonto p);
int AlteraX(tPonto p);
int AlteraY(tPonto p);
float DistanciaDois(tPonto p1, tPonto p2);
int Quadrante(tPonto p);

int main(){
	int qtd = 0, q = 1, qdt = 0;
	tPonto ponto;
	
	ponto = IniciarV();

	scanf("%d",&qtd);
	
	for (q = 1; q <= qtd; q++){
		ponto = LePonto();
		ImprimePnt(ponto);
		qdt = Quadrante(ponto);
		printf(" %d ", qdt);
		ponto = MovXeYSim(ponto);
		ImprimePnt(ponto);
		qdt = Quadrante(ponto);
		printf(" %d\n", qdt);
	}
}

tPonto IniciarV(){
	tPonto ponto;
	ponto.x = 2;
	ponto.y = 2;
	return ponto;
}

tPonto LePonto(){
	tPonto ponto;
	scanf("%d %d", &ponto.x, &ponto.y);
	return ponto;
}

void ImprimePnt(tPonto p){
	printf("(%d,%d)", p.x, p.y);
}

tPonto MovXeYSim(tPonto p){
	p.x = AlteraX(p);
	p.y = AlteraY(p);
	return p;
}

int AlteraX(tPonto p){
	p.x = -p.x;
	return p.x;
}
int AlteraY(tPonto p){
	p.y = -p.y;
	return p.y;
}

float DistanciaDois(tPonto p1, tPonto p2){
	float dist = 0, deltaX = 0, deltaY = 0;
	
	deltaX = p1.x - p2.x;
	deltaY = p1.y - p2.y;
	
	
	dist = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
	
	return dist;
}

int Quadrante(tPonto p){
	if(p.x > 0 && p.y > 0){
		return 1;
	}
	else if(p.x > 0 && p.y < 0){
		return 4;
	}
	else if(p.x < 0 && p.y > 0){
		return 2;
	}
	else if(p.x < 0 && p.y < 0){
		return 3;
	}
	else {
		return 0;
	}
}
