#include <stdio.h>
#include <math.h>

int main (){
	int n = 1, qntnegativa = 0, qntpositiva = 0, somapositiva = 0, somanegativa = 0, i = 1, resultado = 0;
	

	while (i){
	if(n > -100 && n < 100){
	
		resultado = scanf("%d", &n);
		if(resultado == 1){
		
			if(n<0){
				somanegativa = somanegativa + n;
				qntnegativa++;
			} 	else if(n>0){
				somapositiva = somapositiva + n;
				qntpositiva++;
			}
		} else if (resultado == -1 || resultado == 0) {
		break;
		}
	}

	}
	printf("%d %d %d %d", qntnegativa, qntpositiva, somanegativa, somapositiva);
}
