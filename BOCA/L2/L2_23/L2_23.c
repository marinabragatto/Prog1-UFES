#include <stdio.h>

int main(){
	int i = 1, aberto = 0, fechado = 0, j = 1;
	char c = 'a', c1 = 'a';

	printf("RESP:");

	while(i){
		
		scanf("%c",&c);
		if(c == '('){
			aberto++;
			while(j){
				scanf("%c", &c1);
				if(c1 == ')'){
					fechado++;
					if(aberto !=  fechado){
						printf("%c",c1);
					}
					if(aberto == fechado){
						break;
					}
					
				} 
				else if(c1 == '('){
					aberto++;
					if(aberto != fechado){
						printf("%c", c1);
					}
				} else {
					printf("%c",c1);
				}
				
			}
		}

		if(c == '.'){
			break;
		}
	}
	return 0;
}
