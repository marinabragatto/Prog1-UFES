#include <stdio.h>
#include <math.h>

int main(){
	float t = 4.0, c1 = 3.0, c2 = 3.0;
	char x = 'k';
	
	scanf("%f %c",&t,&x);
	
	c1 = (t - 32)*5/9;
	
	c2 = (t*9)/5+32;
	
	if (x =='f') {
		
		printf("%.2f (C)",c1);
		
		
	} else if (x == 'F') {
		printf("%.2f (C)",c1);
		
	} else{
		printf("%.2f (F)",c2);
	}
	
	
	
}
