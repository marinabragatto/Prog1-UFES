#include <stdio.h>
#include <math.h>

int main(){
	
	int x = 7, y;
	
	scanf("%d",&x);
	y = x % 2;
	
	if(y != 0){
		printf("Impar");
		
	}else {
		printf("Par");
	}
}
