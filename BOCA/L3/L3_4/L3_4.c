#include <stdio.h>

void ImprimeMultiplos(int num, int max);
int EhPrimo(int num);

int main(){
	int i = 0, f = 0, aux = 0, result = 0;
	scanf("%d %d", &i, &f);
	for (aux = i + 1; aux < f; aux++){
		result = EhPrimo(aux);
		if (result == 1){
			printf("%d", aux);
			ImprimeMultiplos(aux, f);
		}
	}
}

void ImprimeMultiplos(int num, int max){
	int aux1 = 0, result = 0, i = 1;
	printf("\n");
	for (aux1 = num + 1; aux1 < max ; aux1++){
		result = aux1%num; 
		if (result == 0){
			printf("%d ", aux1);
			i = 2;
		}
	}
	
	if (i == 1){
		printf("*\n");
	} else {
		printf("\n");
	}
	
}





int EhPrimo(int num){
	int aux1 = 0, result = 0;
	if (num == 2){
		result = 1;
	}
	for (aux1 = 2; aux1 < num; aux1++ ){
		result = num%aux1;
		if (result == 0){
			break;
		} else {
			result = 1;
		}	
	}
	return result;
}
