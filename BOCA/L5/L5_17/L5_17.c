#include <stdio.h>
#include <stdlib.h>


int main (){
	char lista[501][501];
	int i = -1, j = 0, ret  = 1;
	
	while(ret == 1) {
		i++;
		scanf("%*[^a-zA-Z]");
		ret = scanf("%[a-zA-Z]", lista[i]);
		scanf("%*[^a-zA-Z]");

		
	} 

	
	
	for(j = i - 1; j >= 0; j--){
		printf(" %s", lista[j]);
	}
	printf(" ");
	return 0;	
}

