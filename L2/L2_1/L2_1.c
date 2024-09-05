#include <stdio.h>
#include <math.h>

int main(){
	int max = 0, min = 0; 
	
	scanf("%d %d",&min,&max);
	printf("RESP:");
	min = min + 1;
	while(min<max){
		if (!(min%2)){
			printf("%d ",min);
		}
		min++;
	}
	
}
