#include <stdio.h>
#include <math.h>

int main (){
	int n = 0;
	double s1 = 0, s2 = 0, s3 = 0, i = 1.0, z = 1.0, f = 1, exp = 1.0, e = 1.0;
	
	scanf("%d",&n);
	if(n == 1)
	{
		for (i = 1.0, z = 1.0; i <= 99, z <= 50; z++, i = i + 2 )
		{
			f = (i/z);
			s1 = s1 + f;
			if (i == 99 && z == 50)
			{
				printf("%.6f",s1);
			}
		}	
	} else if(n == 2){
		for (exp = 1.0, z = 50.0; exp <= 50, z >= 1.0 ; z--, exp++ ){
			e = pow (2.0,exp);
			f = e/(double)z;
			s2 = s2 + f;
			if (exp == 50 && z == 1){
				printf("%.6f",s2);
			}
		}
	} else if (n == 3){
			for (i = 1.0; i <= 10; i++){
				f = 1/i;
				s3 = s3 + f;
				if (i == 10){
					printf("%.6f", s3);
				}
			}
				
			
	} else 
	return 0;
	
	}

	
