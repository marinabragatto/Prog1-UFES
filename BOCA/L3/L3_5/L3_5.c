#include <stdio.h>

int Propriedade(int num);

int main (){
	int ajuda = 0, i = 0, f = 0, aux = 0;
	
	scanf ("%d %d", &i, &f);
	if ((i != 1000 && f != 9999) && (i < f)){
	
		for (aux = i + 1; aux < f; aux++){
			ajuda = Propriedade(aux);
			if (ajuda){
				printf("%d\n", aux);
			}
		}		
	}
}

int Propriedade(int num){
	int m = 0, rm = 0, c = 0, rc = 0, d = 0, u = 0, num1 = 0, num2 = 0, pot = 0, result;
	
	m = num/1000;
	rm = num%1000;
	c = rm/100;
	rc = rm%100;
	d = rc/10;
	u = rc%10;
	
	num1 = (10*m) + c;
	num2 = (10*d) + u;
	pot = num1 + num2;
	
	if ((pot*pot) == num){
			result = 1;
	} else {
		result = 0;
	}
		
	return result;	
}

