#include <stdio.h>

int EhPrimo(int num);

int main(){
	int i = 0, f = 0, aux = 0, result = 0;
	scanf("%d %d", &i, &f);
	for (aux = i + 1; aux < f; aux++){
		result = EhPrimo(aux);
		if (result == 1){
			printf("%d ", aux);
		}
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
