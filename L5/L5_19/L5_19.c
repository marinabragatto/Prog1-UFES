#include <stdio.h>

int ComparaStg(char c1);
void LeMatrizDeChar(int l, int c, char m[l][c]);
int QtdDeTerra(int l, int c, char m[l][c]);
void AvancaMare(int l, int c, char m[l][c], int h);
void Inicializa(int l, int c, int jah[l][c]);
void ImprimeMatriz(int l, int c, char m[l][c]);

int main(){
  int l = 0, c = 0, h = 0, terra = 0, i = 0, j = 0, terrafinal = 0;

  scanf("%d", &h);
  scanf("%d %d", &c, &l);

  char m[l][c];

  LeMatrizDeChar(l, c, m);

  terra = QtdDeTerra(l, c, m);

  AvancaMare(l, c, m, h);

  terrafinal = QtdDeTerra(l, c, m);

  printf("%d %d\n", terra, terrafinal);

  return 0;	
}

void Inicializa(int l, int c, int jah[l][c]){
  int i = 0, j = 0;
  for(i = 0; i < l; i++){
    for(j = 0; j < c; j++){
      jah[i][j] = 0;
    }
  }
}

void FlagQueJaFoiModificado(int l, int c, int jah[l][c], int i, int j){
  jah[i][j] = 1;
}

int NaoColocouFlag(int l, int c, int jah[l][c], int i, int j){
  if(jah[i][j] == 0){
    return 1;
  }
  else if(jah[i][j] == 1){
    return 0;
  }
}



void LeMatrizDeChar( int l, int c, char m[l][c]){
  int i = 0, j = 0;
  for(i = 0; i < l; i++){
    for(j = 0; j < c; j++){
      scanf("%c", &m[i][j]);
    }
    scanf("%*c");
  }
}

int QtdDeTerra(int l, int c, char m[l][c]){
  int i = 0, j = 0, terra = 0;

  for(i = 0; i < l; i++){
    for(j = 0; j < c; j++){
      if(ComparaStg(m[i][j]) == 2){
      terra++;
      }
    }
  }
  return terra;
}

int ComparaStg(char c1){
  if (c1 == '1'){
    return 3;
  }
  if(c1 == '0'){
    return 2;
  }
  return 0;
}

void AvancaMare(int l, int c, char m[l][c], int h){
  int hi = 0, i = 0, j = 0;


  //VETOR QUE VERIFICA SE JA FOI ALTERADO
  int jah[l][c];
  Inicializa(l, c, jah);

  for (hi = 1; hi <= h; hi++){
    for(i = 0; i < l; i++){
      for(j = 0; j < c; j++){
      	if(m[i][j] == '1'){
        	if(i != 0 && NaoColocouFlag(l, c, jah, i, j)){
         		if(m[i - 1][j] == '0'){
           			m[i - 1][j] = '1';
           			FlagQueJaFoiModificado(l, c, jah, i - 1, j);
        	  	}
       		}
        	if(i != l - 1 && NaoColocouFlag(l, c, jah, i, j)){
        		if(m[i + 1][j] == '0'){
           			m[i + 1][j] = '1';
            		FlagQueJaFoiModificado(l, c, jah, i + 1, j);
          		}
        	}

        	if(j != 0 && NaoColocouFlag(l, c, jah, i, j)){
         		if(m[i][j - 1] == '0'){
            	m[i][j - 1] = '1';
            	FlagQueJaFoiModificado(l, c, jah, i, j - 1);
        		}
        	}

        	if(j != c - 1 && NaoColocouFlag(l, c, jah, i, j)){
        		if(m[i][j + 1] == '0'){
        		    m[i][j + 1] = '1';
            		FlagQueJaFoiModificado(l, c, jah, i , j + 1);
          		}
        	}	
		}
	  }
    }
    Inicializa(l, c, jah);
  }
}
