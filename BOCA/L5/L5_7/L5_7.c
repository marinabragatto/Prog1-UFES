#include <stdio.h>

int main(){
	int qtd = 0, var = 0, q = 0, h = 1, var1 = 0;
	scanf("%d", &qtd);
	
	
	if (qtd == 1){
		printf("NAO");
		return 0;
	}
	
	int n[qtd];
	
	
	for (q = 0; q < qtd; q++){
		scanf("%d", &n[q]);
	}
	
	var = n[1] - n[0];
	
	for (q = 2; q < qtd ; q++){
		var1 = n[q] - n[q - 1];
		if (var1 == var){	
			h = 1;
			continue;
		}
		else {
			h = 2;
			break;
		}
	}
	if (h == 2){
		printf("NAO");
		
	}
	else if(h == 1){
		printf("RESP:%d", var);
	}
	return 0;
}
