#include <stdio.h>
#include <math.h>

int main(){
	
	int n,u,d,c,n1,u2,d2,c2; 
	
	
	scanf("%d %d",&n1,&n);
	
	c = n1/100;
	u = n1%10;
	d = (n1%100)/10;	
	
	u2 = u%2;
	d2 = d%2;
	c2 = c%2;	
	
	if((n == 1)&&(u2!=0)){
		 
		 printf("IMPAR");
		
		
		
	} else if ((n == 1)&&(u2 == 0)){
		
		printf("PAR");
		
	} else if ((n == 2)&&(d2!=0)){
		 
		 printf("IMPAR");
		
		
		
	} else if ((n == 2)&&(d2 == 0)){
		
		printf("PAR");
		
		
	} else if((n == 3)&&(c2!=0)){
		 
		 printf("IMPAR");
		
		
		
	} else if ((n == 3)&&(c2 == 0)){
		printf("PAR");
		
	}
	
	return 0;
	
}
