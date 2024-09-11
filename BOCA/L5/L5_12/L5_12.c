#include <stdio.h>
#include <stdlib.h> 

void ConcatenaString(char * str1, char * str2, char * strOut){
	int i = 0, j = 0, qtd = 0, q = 0;

	for (i = 0; str1[i] ; i++);

	for(j = 0; str2[j]; j++);

	qtd = i + j;

	for(q = 0; q < i; q++){
		strOut[q] = str1[q]; 
	}

	for(q = i, j = 0 ; qtd > q - 1; q++, j++){
		strOut[q] = str2[j];
	}

//	printf("%d %d", i, j);

}

int main(){ 
	char nome[1000]; 
	char sobrenome[1000]; 
	char nomeCompleto[2000]; 

	while ( scanf("%s ", &sobrenome) == 1 && scanf("%s\n", &nome) == 1){ 
		ConcatenaString(nome, sobrenome, nomeCompleto); 
		printf("%s\n", nomeCompleto); 
	 } 

		return 0;     
} 
