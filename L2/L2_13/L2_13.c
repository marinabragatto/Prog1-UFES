#include <stdio.h>
#include <math.h>

int main (){
	char a = 'c';

	while ((a != '.') && (a != '?') && (a != '!')){
	
		scanf("%c",&a);

		if(a >= 97 && a <= 122){
			a = a - 32;
			printf("%c",a);
			
		} else {
			printf("%c",a);
		}
	}

	
}
