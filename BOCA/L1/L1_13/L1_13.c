#include <stdio.h>
#include <math.h>

int main (){
	int p = 8, i = 7, resto;
	scanf("%d %d",&p,&i);
	
	resto = (i % p);
	
	if (p==i){
		
		printf("RESP:%d",p);
		
		
	} else if((p<i)&&(resto != 0)){
		
		printf("RESP:%d", resto );
		
		
	} else if((p<i)&&(resto == 0)){
		
		printf("RESP:%d",p);
		
	} else if(p>i){
		
		printf("RESP:%d",i);
		
	}
	
	return 0;
	
}
