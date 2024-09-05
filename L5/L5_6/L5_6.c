#include <stdio.h>


int main(){
	int qtd1 = 0, qtd2 = 0, j = 0, q = 0, total = 0;
	

	scanf("%d", &qtd1);
	
	int n1[qtd1];
	
	for (q = 0; q < qtd1; q++){
		scanf("%d", &n1[q]);

	}
	
	scanf("%*c");
	
	scanf("%d", &qtd2);
	
	int n2[qtd2];

	for (j = 0; j < qtd2 ; j++){
		scanf("%d", &n2[j]);
	}

	q = 0;
	j = 0;
	
	for (q = 0; q < qtd1 ; q++){
		for(j = 0; j < qtd2 ; j++){
			if(n1[q] == n2[j]){
				total++;
			}		
		}
	}
	if(total == 0){
		printf("NENHUM");
	}
	else if (total >= qtd1){
		printf("TODOS");	
	}
	else if (total < qtd1){
		printf("PARCIAL");
	}
	return 0;
}
	

