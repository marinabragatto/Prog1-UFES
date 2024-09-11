#include <stdio.h>
#include <math.h>

int main (){
	int n = 0, m = 0, x = 0, y = 0, div = 0, resto = 0, mult = 0, soma = 0;
	
	scanf ("%d %d", &n, &m);
	
	if((n>1000) && (m<9999) && (n < m)){
		for (x = n + 1; x < m; x++)
		{
			div = x/100;
			resto = x%100;
			mult= (div+resto)*(div+resto);
			if(mult == x)
			{
				printf("%d\n", mult);
			}
		}
	}	

}
