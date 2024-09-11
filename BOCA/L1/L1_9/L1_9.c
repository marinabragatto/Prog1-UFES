#include <stdio.h>

int main(){
	 char z = 'k', y;
	 
	 scanf("%c",&z);
	 
	 y = (z - 32);
	 
	 if((z>=97)&&(z<=122)){
	 	
	 	printf("%c(%d)",y,y);
	 	
	 } else if((z>=65)&&(z<=90)){
	 	
	 	printf("A letra deve ser minuscula!");
	 	
	 } else{ 
	 printf("Nao e letra!");
	 }
	 
	 return 0;
}
