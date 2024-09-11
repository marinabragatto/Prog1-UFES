#include <stdio.h>
#include <math.h>

#define PI 3.141592
int main(void){
  
  float raio;
  scanf("%f",&raio);
  
  float area = PI * (raio*raio);

  float raio2 = raio/sqrt((float)2);
  
  printf("%.2f %.2f",area,raio2);
  
}
