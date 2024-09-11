#include <stdio.h>

float Soma(float num1, float num2); 
float Subtracao(float num1, float num2); 
float Divisao(float num1, float num2); 
float Multiplicacao(float num1, float num2); 
float Inicializa(float num1, float num2, char operador, char lixo);

int main (){
	float num1 = 0, num2 = 0, result = 0, i = 1, ajuda = 0;
	char lixo = 'a', operador = 'a';
	scanf("%f %f %c%c", &num1, &num2, &operador, &lixo); 
	num1 = Inicializa(num1, num2, operador, lixo);
	
	if (lixo != 10){
			while (i){
				ajuda = scanf("%f %c%c", &num2, &operador, &lixo);
				if (ajuda != -1 && ajuda != 0){
					if (operador == '/'){
						result = Divisao(num1, num2);
						num1 = result;
					} else if (operador == '*'){
						result = Multiplicacao(num1, num2);
						num1 = result;
					} else if (operador == '+'){
						result = Soma(num1, num2);
						num1 = result;
					} else if (operador == '-'){
						result = Subtracao(num1, num2);
						num1 = result;
					} 
					if (lixo == 10){
						break;
					}
					
				} else 
					break;
			} 
	}
	printf("%.2f", num1);
	
	
	
}

float Soma(float num1, float num2){
	float soma;
	soma = num1 + num2;
	return soma;
}

float Subtracao(float num1, float num2){
	float subtracao;
	subtracao = num1 - num2;
	return subtracao;
}

float Divisao(float num1, float num2){
	float divisao;
	divisao = num1/num2;
	return divisao;
}

float Multiplicacao(float num1, float num2){
	float multiplicacao;
	multiplicacao = num1*num2;
	return multiplicacao;	
}
float Inicializa(float num1, float num2, char operador, char lixo){
	float result = 0;
	if (operador == '/'){
		result = Divisao(num1, num2);
	}
	if (operador == '*'){
		result = Multiplicacao(num1, num2);
	}
	if (operador == '+'){
		result = Soma(num1, num2);
	}
	if (operador == '-'){
		result = Subtracao(num1, num2);
	}
	return result;		
}
