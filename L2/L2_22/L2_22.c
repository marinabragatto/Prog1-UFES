#include <stdio.h>
#include <math.h>
//programa que calcula a soma dos algarismos de qualquer numero
int main (){
	int n1 = 0, i = 1, tamanho = 0, j = 0, soma = 0, casa = 0, h = 0;
	
	scanf("%d", &n1);
	//while(al!=1)
	if (n1>9){
	
	while (n1>9){
	for(i = 1, j = 1; (n1/i) != 0 ; i = (i*10) , j++){
	
		tamanho = j;
		
	}
	j = j - 2;
	for (h = pow(10,j) ; h !=  0; (n1 = n1%h) , (h = h/10)){
		casa = n1/h;
	
		soma = soma + casa;
		
	}
	n1 = soma;
	if (n1>9){
		soma = 0;
	}
	}	
	printf("RESP:%d",soma);
	} else {
		printf("RESP:%d",n1);
	}
	
}

