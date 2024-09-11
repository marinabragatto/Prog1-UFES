#include <stdio.h>



int main(){
	int num = 0, qtd = 0, q = 0;
	
	scanf("%d", &num);
	
	scanf("%d", &qtd);
	
	int n[qtd - 1];
	
	for (q = 0; q < qtd ; q++){
		scanf("%d", &n[q]);
		if (n[q] == num){
			printf("RESP:%d", q);
			return 0;
		} else {
			
		}
	}
	
	
	printf("RESP:%d",qtd);
	
	
	return 0;
	
}
