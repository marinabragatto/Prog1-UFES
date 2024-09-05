#include <stdio.h>

int EhPar (int x);
void PrintaPares (int N);
void PrintaImpares (int N);

int main(){
	int ver = 2, lim = 1;
	
	scanf("%d %d", &ver, &lim);
	
	if(ver == 0){
		PrintaPares (lim);
	} else if (ver == 1){
		PrintaImpares (lim);
	}
	
}

int EhPar (int x){
	int resto = 0;
	resto = x%2;
	if(resto == 0){
		return 1;
	} else {
		return 0;
	}
}
void PrintaPares (int N){
	int num = 2, count = 0;
	
	for(num = 2; count != N ; num++){
		if(EhPar(num)){
			printf("%d ", num);
			count++;
		}
	}
	
}
void PrintaImpares (int N){
	int num = 1, count = 0;
	for(num = 1; count != N ; num++){
		if(!(EhPar(num))){
			printf("%d ", num);
			count++;
		}
	}
	
}
