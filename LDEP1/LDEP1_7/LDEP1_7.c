#include <stdio.h>
#include <math.h>

int main(){
	
	int n1 = 0, n2 = 0, n3 = 0;
	float media = 4.0;

	scanf("%d %d %d", &n1, &n2, &n3);
	scanf("%*[^\n]");
	scanf("%*c");
	

	media = (n1 + n2 + n3)/3.0;
	
	
	printf("Notas acima da media:");

	if (n1 >= media){ 
		printf(" %d", n1);
	}
	if (n2 >= media){ 
		printf(" %d", n2);
	}
	if (n3 >= media){ 
		printf(" %d", n3);
	}
	printf("!");
	
	return 0;
}

