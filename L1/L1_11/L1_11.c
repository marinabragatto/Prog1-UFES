#include <stdio.h>
#include <math.h>

int main(){
	int x = 6;
	scanf("%d",&x);
	
	if(x==1){
		printf("Jan.");
		
	} else if(x==2){
		printf("Fev.");
		
	} else if(x==3){
		printf("Mar.");
		
	} else if(x==4){
		printf("Abr.");
		
	} else if(x==5){
		printf("Mai.");
		
	} else if(x==6){
		printf("Jun.");
		
	} else if(x==7){
		printf("Jul.");
		
	} else if(x==8){
		printf("Ago.");
		
	} else if(x==9){
		printf("Set.");
		
	} else if(x==10){
		printf("Out.");
		
	} else if(x==11){
		printf("Nov.");
		
	} else if(x==12){
		printf("Dez.");
		
	} else {
		printf("Invalido.");
	}
	return 0;	
}
