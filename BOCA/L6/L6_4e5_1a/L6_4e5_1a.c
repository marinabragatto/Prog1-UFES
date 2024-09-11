#include <stdio.h>

typedef struct {
	int idm; 
	int idp;
	int tamanho; 
	int cde;
	char frase[10];
}tPacote;

tPacote LePacote();
void ImprimePacote(tPacote pacote);

int main(int argc, char * argv []){
  int qtd = 0, q = 1, idm = 0, idp = 0, tamanho = 0, t = 1, cde = 0, i = 1;
  tPacote pacote;
  char c = 'a', lixo = 'a';

  scanf("%d", &qtd);
  
  for (q = 1; q <= qtd; q++){
	pacote = LePacote();
	ImprimePacote(pacote);

  }

  return 0;

}

tPacote LePacote(){
	tPacote pacote;
	int t = 0, i = 0;
	char lixo = 'a';
	scanf("%d %d %01d", &pacote.idm, &pacote.idp, &pacote.tamanho);
    for (i = 0; i < 10 ; i++){
      pacote.frase[i] = '\0';
    }
  
    for (t = 1, i = 0; t <= pacote.tamanho; t++, i++){
      scanf("%c", &pacote.frase[i]);
      if(t>9){
         break;
      }
    }
  

  	
  	if(pacote.tamanho < 9){
          if(pacote.tamanho != 0){
              do{
  		    	scanf("%c", &lixo);
                  t++;
		      } while(t <= 9);
          } else {
              do{
  		    	scanf("%c", &lixo);
                  t++;
		      } while(t < 9);
          }
  	
	  }  	

    scanf("%d\n", &pacote.cde);
  return pacote;
}

void ImprimePacote(tPacote pacote){
	printf("PCT: %d,%d,%d,%s,%d\n", pacote.idm, pacote.idp, pacote.tamanho,pacote.frase,pacote.cde);
}
