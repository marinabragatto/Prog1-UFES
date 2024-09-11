#include <stdio.h>
#include <math.h>

typedef struct{
	int x;
	int y;
}tPonto;

typedef struct{
	tPonto p1;
	tPonto p2;
}tReta;

tReta IniciarReta();
tPonto IniciarPonto();
tReta LeReta ();
tPonto LePonto ();
float CalculaDist(tPonto atual, tPonto ant);
tPonto PontoInicial(tReta r);
tPonto PontoInicialPontos(tPonto p1, tPonto p2);
int TamanhoReta(tReta r);
int Proximidade(tReta r, tPonto p);
tReta MoverReta(tReta r);
tPonto MoverPonto(tPonto p);
void ImprimePonto(tPonto p);
void PrintaReta(tReta r);

int main(){
	int qtd = 0, q = 1, res = 0;
	tPonto ponto;
	tReta reta;
	ponto = IniciarPonto();
	reta = IniciarReta();
	
	scanf("%d", &qtd);
	
	for(q = 1; q <= qtd ; q++){
		ponto = LePonto();
		reta = LeReta();
		res = Proximidade(reta, ponto);
		if(res == 1){
			printf("EQUIDISTANTE\n");
		} 
		else if(res == 2){
			printf("FIM\n");
		} 
		else if(res == 3){
			printf("INICIO\n");
	
		}
	}
	
	return 0;
}

tReta IniciarReta(){
	tReta reta;
	reta.p1 = IniciarPonto();
	reta.p2 = IniciarPonto();

	return reta;
}
tPonto IniciarPonto(){
	tPonto p;
	p.x = 2;
	p.y = 2;
	return p;
}

tReta LeReta (){
	tReta reta;
	reta.p1 = LePonto();
	reta.p2 = LePonto();
	return reta;
}

tPonto LePonto (){
	tPonto p;
	scanf("%d %d", &p.x, &p.y);
	return p;
}

float CalculaDist(tPonto p1, tPonto p2){
	float dis = 0, deltaX = 0, deltaY = 0;
	
	
	deltaX = p1.x - p2.x;
	deltaY = p1.y - p2.y;
	
	dis = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

	return dis;
}

tPonto PontoInicial(tReta r){
	tPonto pIni;
	pIni = r.p1;
	return pIni;
}

tPonto PontoFinal(tReta r){
	tPonto pFin;
	pFin = r.p2;
	return pFin;
}

int TamanhoReta(tReta r){
	float tam = 0;
	
	tam = CalculaDist(r.p1, r.p2);

	return tam;
}

int Proximidade(tReta r, tPonto p){
	float dis1 = 0, dis2 = 0;
	
	dis1 = CalculaDist(r.p1, p);
	dis2 = CalculaDist(r.p2, p);
	
	if(dis1 == dis2){
		return 1;
	}
	else if (dis1 > dis2){
		return 2;
	} else {
		return 3;
	}
	
}

tReta MoverReta(tReta r){
	r.p1 = MoverPonto(r.p1);
	r.p2 = MoverPonto(r.p2);
	return r;
}

tPonto MoverPonto(tPonto p){
	int deltaX = 0, deltaY = 0;
	scanf("%d %d", &deltaX, &deltaY);
	p.x = p.x + deltaX;
	p.y = p.y + deltaY;
	return p;
}

void PrintaReta(tReta r){
	printf("[");
	ImprimePonto(r.p1);
	printf(":");
	ImprimePonto(r.p2);
	printf("]");
}

void ImprimePonto(tPonto p){
	printf("(%d,%d)", p.x, p.y);
}
