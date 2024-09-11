
int main(){
	int n = 3, max = 0, div = 2;
	
	scanf("%d",&max);
	if (max>=2){
	printf("2 ");
	}
	
	while(n <= max){ 
		while(div < n){
			if ((n % div) == 0){
				break;  
			}
			div++;
			}
			 
		if (div == n ){
			printf("%d ",n);
	
		}
		div = 2;
		n++;
		
	}
	
}
