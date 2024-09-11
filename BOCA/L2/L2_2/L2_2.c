#include <stdio.h>
#include <math.h>

int main(){
	int max = 0, min = 0; 
	
	scanf("%d %d",&min,&max);
	min = min + 1;
	while(min<max){
		if (!(min%3)){
			printf("%d ",min);
		} else if (!(min%4)){
			printf("%d ",min);
		} else if (!(min%7)){
			printf("%d ",min);
		}
	
		min++;
	}
	
}
