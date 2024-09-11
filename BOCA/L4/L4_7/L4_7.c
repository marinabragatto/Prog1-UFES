#include <stdio.h>

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
int Quadrante(tPonto p);
int RetaQuad (tReta r);

int main (){
	int qtd = 0, q = 1, res = 0;
	tReta reta;
	
	reta = IniciarReta();
	
	scanf("%d", &qtd);
	
	for(q = 1; q <= qtd ; q++){
		reta = LeReta();
		res = RetaQuad (reta);
		if(res == 2){
			printf("DIFERENTE\n");
		} 
		else if(res == 1){
			printf("MESMO\n");
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

int RetaQuad (tReta r){
	int qP1 = 0, qP2 = 0;
	qP1 = Quadrante(r.p1);
	qP2 = Quadrante(r.p2);
	
	if(qP1 == 0 || qP2 == 0){
		return 2;
	}
	else if(qP1 == qP2){
		return 1;
	}
	else if (qP1 != qP2){
		return 2;
	}
		
}
