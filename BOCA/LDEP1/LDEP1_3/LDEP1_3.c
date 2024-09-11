#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    int a = 0, i = 2;

    scanf("%d",&a);


    while(i < a){
        if(!(i % 2 )){
          	printf("%d ",i);
        } else if(!(i % 3)){
            printf("%d ", i);
		} 
		i++;
	}
    printf("\n");
    return 0;
}
