#include <stdio.h>
#include <math.h>

int main (){
	float x,y,z,w;
	scanf("%f %f %f %f",&x,&y,&z,&w);
	printf("%.2f",(z-x)*2+(w-y)*2);
	return 0;
}
