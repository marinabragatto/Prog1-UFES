#include <stdio.h>
#include <math.h>

int main(){
	int N1 = 4, N2 = 3;
	scanf("%d %d",&N1,&N2);
	
    if (N1>N2){
    	printf("N1 = %d",N1);
    
	} else if (N1<N2){
		printf("N2 = %d",N2);
		
	} else{
		printf("N1 = N2");
	}
	return 0;
}
