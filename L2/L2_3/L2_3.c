#include <stdio.h>
#include <math.h>

int main(){
	int qt = 0, max = 0, min = 0, min1 = 0, i = 0, somap = 0, somai = 0, num =0, mdsom = 0;
	float y = 0, media = 0;
	
	scanf("%d ",&qt);
	
	
	while (i<qt){
	
			scanf("%d", &num);
			if(num>max){
				max = num;
			} 
			if (num<min || min == 0){
				min = num;
			
			}
			
			if(!(num%2)){
				somap = somap + 1; } 
			if(num%2){
				somai = somai + 1; }
			mdsom = mdsom + num;
			i++;
		
	}
	y = (float)mdsom;
	media = y/qt;
		
	
	
	printf("%d %d %d %d %.6f",max, min, somap, somai, media);
			
	}
		
		
