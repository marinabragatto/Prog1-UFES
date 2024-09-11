#include <stdio.h>
//linha , coluna (linha, coluna)
int main (){
	int linha = 0, coluna = 0, l = 0, c = 0, n1 = 0, enter = 99999, ln1 = 0, cn1 = 0, maior = 0; 
	
	scanf("%d %d", &linha, &coluna);
	
	for(l = 1; l<=linha; l++){
	
		for (c = 1; c<=coluna; c++){
			if(c==1){
				scanf("	%d",&n1);
			} else {
			scanf("%d", &n1);
			}
			if (n1>maior || enter == 99999){
				maior = n1;
				ln1 = l;
				cn1 = c;
				enter++;
				
				
			}
		}
		
	}
	printf("%d (%d, %d)", maior, ln1, cn1);	
}
