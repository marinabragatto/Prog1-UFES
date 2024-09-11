#include <stdio.h>
#include <math.h>


int main (){
	int i = 1, tam = 1, soma = 0, g = 1, l = 1, menor = 0, maior = 0, rep = 0, apro = 0;
	float media = 0, it = 0, somat = 0, des = 0, t = 0;
	
	scanf("%d", &tam);
	int nota[tam];
	for (i = 0; i < tam; i++){
		scanf("%d",&nota[i]);
		soma = soma + nota[i];
		if(maior < nota[i] || g == 1){
			g++;
			maior = nota[i];
		}
		
		if(menor > nota [i] || l == 1){
			l++;
			menor = nota[i];
		}
		
		if(nota[i] < 70){
			rep++;
		}
	
	}
	media = soma/(float)tam;
	
	for (i = 0 ; i < tam ; i++){
	
		t = nota[i] - media;
		
		it = (pow(t , 2))/(float)tam;
		somat = somat + it;
		
	//	printf("%.2f\n", somat);
		
		if(nota[i] > media){
			apro++;
		}
	} 
	
	des = sqrt(somat);
	
	printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d", menor, maior, media, des, apro, rep);
	
	return 0;	
	
}



