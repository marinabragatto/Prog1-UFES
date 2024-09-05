#include <stdio.h>
#include <math.h>

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);
int area (int x1, int y1, int x2, int y2); 

int main(){
	int r1_x1 = 0, r1_y1 = 0, r1_x2 = 0, r1_y2 = 0, r2_x1 = 0, r2_y1 = 0, r2_x2 = 0, r2_y2 = 0, areatotal = 0;;
	
	scanf("%d %d %d %d\n", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
	scanf("%d %d %d %d", &r2_x1, &r2_y1, &r2_x2, &r2_y2);
	
	areatotal = area_total(r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2);
	
	printf("RESP:%d", areatotal);
	
	
}

int area (int x1, int y1, int x2, int y2){
	int lado1 = 0, lado2 = 0, area = 0;
	lado1 = x2 - x1;
	lado2 = y2 - y1;
	area = lado1*lado2;
	return area;
}

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2){
	int arear1 = 0, arear2 = 0, result = 0, area3 = 0;
	
	if(r2_x1 < r1_x2 && r2_y1 < r1_y2){
		arear1 = area(r1_x1, r1_y1, r1_x2, r1_y2);
		arear2 = area(r2_x1, r2_y1, r2_x2, r2_y2);
		area3 = area(r2_x1,r2_y1, r1_x2, r1_y2);
		result = arear1 + arear2 - area3;
		
	} else {
		arear1 = area(r1_x1, r1_y1, r1_x2, r1_y2);
		arear2 = area(r2_x1, r2_y1, r2_x2, r2_y2);
		result = arear1 + arear2;
	}
	return result;
}

