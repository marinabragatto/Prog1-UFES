#include <stdio.h>
#include <math.h>

int main (){
	int n = 0, i = 0, j = 0, x = 2, inicio = 0, final = 0, k = 1, w = 2, multiplos = 0; 
	
	scanf ("%d %d",&inicio, &final);
	
	for (inicio++ ;  inicio < final ; inicio++ )
	{
		
		for (i = 2; i < inicio; i++){
			j = inicio%i;
			if (j == 0)
			{
				x = 3;
				i = i + (2*final);
			
			}
		}
		if (x == 2 && inicio != 1)
		{
			printf("%d\n", inicio);
			for (multiplos = inicio + 1; multiplos < final; multiplos++ )
			{
				k =	multiplos%inicio;
				if (k == 0)
				{
					printf("%d ", multiplos);
					w = 3;
				}
				if (multiplos == final - 1 && (w == 3))
					{
					printf("\n");
					}
				
			
			}
			if (w == 2)
			{
				printf("*\n");
			}
			w = 2;
		} 
		x = 2;
		
		
	}	
	return 0;
}
	

