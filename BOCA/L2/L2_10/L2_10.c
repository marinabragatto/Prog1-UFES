#include <stdio.h>
#include <math.h>

int main (){
	int n = 0, m = 0, fator1 = 0, result = 0, control = 0;
	scanf("%d %d",&n,&m);
	
	
	for (control = n; control <= m; control++)
	{
		for (fator1 = 1; fator1 <= 10; fator1++)
		{
			result = control*fator1;
			printf("%d x %d = %d\n", control, fator1, result);
		
		}
		
	}
	return 0;
}
