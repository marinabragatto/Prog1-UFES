#include <stdio.h>
#include <math.h>

int main(){
	int x1 = 9, x2 = 8 , xp = 7, y1 = 8, y2 = 6, yp = 7;
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&xp,&yp);
	// e se os pontos forem ao contrario
	
	if ((yp>=y1)&&(yp<=y2)&&(xp>=x1)&&(xp<=x2)){
		
		printf("Dentro");
		
		
	} else if((yp>=y1)&&(yp<=y2)&&(xp<=x1)&&(xp>=x2)){
		
		printf("Dentro");
		
		
	} else if((yp<=y1)&&(yp>=y2)&&(xp>=x1)&&(xp<=x2)){
		
		printf("Dentro");
		
		
	} else if((yp<=y1)&&(yp>=y2)&&(xp<=x1)&&(xp>=x2)){
		
		printf("Dentro");
	
		
		
	} else {
		 
		 printf("Fora");
	}
	 
	 return 0;
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
