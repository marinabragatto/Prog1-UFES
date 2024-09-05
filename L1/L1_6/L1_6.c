#include <stdio.h>
#include <math.h>

int main() {
	int n1 = 3, n2 = 2; 
	float media = 4.0;
	
	scanf("%d %d",&n1,&n2);
	
	media = (n1 + n2) / 2.0;
	
	if(media>=7){
		printf("%.1f - Aprovado",media);
		
		
	} else if(media<5){
	    printf("%.1f - Reprovado",media);
	    
	    
	} else { 
	    printf("%.1f - De Recuperacao",media);
	}
	
    return 0;
	
}
