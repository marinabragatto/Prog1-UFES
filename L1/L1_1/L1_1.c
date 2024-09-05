#include <stdio.h>
#include <math.h>

int main(){
  int x;
  int z;
  scanf("%d %d",&x,&z);  
  float soma = sqrt(x) + sqrt(z);
  printf("%.2f",soma);
  return 0;
}
