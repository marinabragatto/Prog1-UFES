#include <stdio.h>
#include <math.h>

float CalculaFuncao(float a, float b, float c, float d, float x);

int main (){
	int i = 0, f = 0, xVale = 0, xPico = 0, exPico = 0, exVale = 0;
	float a = 1.0, b = 1.0, c = 1.0, d = 1.0, x = 0, valor = 1.0, anterior = 1.0, sucessor = 1.0;
	
	scanf ("%f %f %f %f %d %d", &a, &b, &c, &d, &i, &f);
	
	anterior = CalculaFuncao(a, b, c, d, i - 1);
	valor = CalculaFuncao(a, b, c, d, i );
	sucessor = CalculaFuncao(a, b, c, d, i + 1);
	//busca vale	
	if ((anterior > valor && valor > sucessor) || (anterior < valor && valor > sucessor)){
		if (anterior < valor && valor > sucessor){
			printf("Pico em x=%d\n", i);
			exPico = 2;
		}
		anterior = valor;
		for (x = i + 1; x <= f; x++){
			valor = CalculaFuncao(a, b, c, d, x);
			if(valor > anterior){
				xVale = x - 1;
				printf("Vale em x=%d\n",xVale);
				anterior = valor;
				exVale = 2;
				break;
			}
			anterior = valor;
		}
		
		for (x++ ; x <= f; x++){
			valor = CalculaFuncao(a, b, c, d, x);
			if (valor < anterior){
				xPico = x - 1;
				printf("Pico em x=%d\n",xPico);
				anterior = valor;
				exPico = 2;
				break;
			}
			anterior = valor;
		}
						
		
	} else if ((anterior < valor && valor < sucessor) || (anterior > valor && valor < sucessor)) {
		if (anterior > valor && valor < sucessor){
			printf("Vale em x=%d\n", i);
		}
		anterior = valor;
		//procura pico
		for (x = i + 1; x <= f; x++){
			valor = CalculaFuncao(a, b, c, d, x);
			if(valor < anterior){
				xPico = x - 1;
				printf("Pico em x=%d\n",xPico);
				anterior = valor;
				exPico = 2;
				break;
			}
			anterior = valor;
		}
		
		for (x++ ; x <= f; x++){
			valor = CalculaFuncao(a, b, c, d, x);
			if (valor > anterior){
				xVale = x - 1;
				printf("Vale em x=%d\n",xVale);
				anterior = valor;
				exVale = 2;
				break;
			}
			anterior = valor;
		} 
		
		
	}
	
	if (exPico == 0){
		printf("Nao ha pico\n");
	} 
	if (exVale == 0){
		printf("Nao ha vale");
	}
	


}

float CalculaFuncao(float a, float b, float c, float d, float x){
	float result = 1.0;
	result = a*(pow(x,3)) + b*(pow(x,2)) + c*x + d;
	return result;
}
