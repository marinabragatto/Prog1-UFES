#include <stdio.h>
#include <math.h>

int main (){
	char a = 'c';
	int i = 1;


	while ((a != '.') && (a != '?') && (a != '!')){
	
		scanf("%c",&a);
		if(i == 1){
			printf("RESP:");
		}
		if(a != ' '){
			printf("%c",a);
		}
		i++;
	}

	
}
