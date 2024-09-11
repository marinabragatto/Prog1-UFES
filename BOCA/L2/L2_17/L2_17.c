#include <stdio.h>

int main(){
	//numeros ate 26
	int n1 = 0, n2 = 0, i = 1, n2real = 0, rmspace = 0;
	char c = 'a', space = 'a', k = 'a';
	scanf("%d %d",&n1, &n2);
	if(n2>26){
	n2 = n2%26;
	}
	while(i){
		if(	c != '.'){
			if(rmspace == 0){
				scanf("%c%c", &space, &c);
				rmspace++;
			}else {
				scanf("%c",&c);
			}
			//codificar 1 e descodificar 2
			if(n1 == 1){
				if(c>=97 && c <=122){
					if(c>122-n2){
						c = c-26+n2;
						printf("%c",c);
					} else if(c<=122-n2){
						c=c+n2;
						printf("%c",c);
					}
				
				} else {
					printf("%c",c);
				}
			
		
		
		
			} else if (n1 == 2){
				if(c>=97 && c <=122){
					if(c<97+n2){
						c = c+26-n2;
						printf("%c",c);
					} else if(c>=97+n2){
						c=c-n2;
						printf("%c",c);
					}
				
				} else {
					printf("%c",c);
				}
			
			
			
		
			} else{
				printf("Operacao invalida.");
				break;
			}
		
	
	}	else {
		break;
	}
		
	}
	

	
}
