#include <stdio.h> 
#include <stdlib.h> 

int ComparaString(char * str1, char * str2){
  int j = 0, i = 0, res = 0, c = 0;
  for (i = 0; str1[i]; i++);
  for (j = 0; str2[j]; j++);

  if(j != i){
    return 0;
  }
  else{
    for(c = 0; c <= i; c++){
      if(str1[c] != str2[c]){
        return 0;
      }
    }
  }

  return 1;
}


int main(){ 
 char str1[1000]; 
 char str2[1000]; 

 while ( scanf("%s", &str1) == 1 && scanf("%s", &str2) == 1){ 
  if ( ComparaString(str1, str2) )  
   printf("IGUAL\n"); 
  else 
   printf("DIFERENTE\n"); 
 } 

    return 0;     
} 