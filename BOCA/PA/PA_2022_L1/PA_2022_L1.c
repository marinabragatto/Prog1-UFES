#include <stdio.h>
#include <math.h>

int main (){
	int n1 = 0, n2 = 0, aux, m1 = 0, c1 = 0, d1 = 0, u1 = 0, m2 = 0, c2 = 0, d2 = 0, u2 = 0, rc = 0, rd = 0, rm = 0;
	char c = 'a';
	scanf("(%c,%d,%d)",&c , &n1, &n2);
	
	if(n1>=1000 && n1<=9999){
		m1 = n1/1000;
		rm = n1%1000;
		c1 = rm/100;
		rc = rm%100;
		d1 = rc/10;
		rd = rc%10;
		u1 = rd;
	} else if(n1>=100){
		c1 = n1/100;
		rc = n1%100;
		d1 = rc/10;
		rd = rc%10;
		u1 = rd;
	} else if(n1>=10){
		d1 = n1/10;
		rd = n1%10;
		u1 = rd;
	}  else if(n1>=0){
		u1 = n1;
	}
	
	if(n2>=1000 && n2<=9999){
		m2 = n2/1000;
		rm = n2%1000;
		c2 = rm/100;
		rc = rm%100;
		d2 = rc/10;
		rd = rc%10;
		u2 = rd;
	} else if(n2>=100){
		c2 = n2/100;
		rc = n2%100;
		d2 = rc/10;
		rd = rc%10;
		u2 = rd;
	} else if(n2>=10){
		d2 = n2/10;
		rd = n2%10;
		u2 = rd;
	}  else if(n2>=0){
		u2 = n2;
	}
	
	
	if ((c > 96 && c < 128) || (c > 64 && c < 91)){
		if (u2 != 0 && d1 != 0 && d2 != 0 && c1 != 0 && c2 != 0 && m1 != 0 && m2 != 0 && u1 != 0){
	
			printf("(%d%d%d%d%d%d%d%d)\n",m2,m1,c2,c1,d2,d1,u2,u1);
		} else if (m2 != 0){
		
			printf("(%d%d%d%d%d%d%d%d)\n",m2,m1,c2,c1,d2,d1,u2,u1);
			
		
		}else if(u2 == 0 && d1 == 0 && d2 == 0 && c1 == 0 && c2 == 0 && m1 == 0 && m2 == 0 && u1 != 0){
		
			printf("(%d)\n",u1);
		
		} else if(u2 != 0 && d1 == 0 && d2 == 0 && c1 == 0 && c2 == 0 && m1 == 0 && m2 == 0){
		
			printf("(%d%d)\n",u2,u1);
	
		}else if(d1 != 0 && d2 == 0 && c1 == 0 && c2 == 0 && m1 == 0 && m2 == 0){
		
			printf("(%d%d%d)\n",d1,u2,u1);
	
		} else if(d2 != 0 && c1 == 0 && c2 == 0 && m1 == 0 && m2 == 0){
		
			printf("(%d%d%d%d)\n",d2,d1,u2,u1);
		
		
			
		} else if(c1 != 0 && c2 == 0 && m1 == 0 && m2 == 0 ){
		
			printf("(%d%d%d%d%d)\n",c1,d2,d1,u2,u1);
			
		} else if(c2 != 0 && m1 == 0 && m2 == 0){
		
			printf("(%d%d%d%d%d%d)\n",c2,c1,d2,d1,u2,u1);
		} else if(m1 != 0 && m2 == 0){
		
			printf("(%d%d%d%d%d%d%d)\n",m1,c2,c1,d2,d1,u2,u1);
		}
		
		
		
		
		
		
	} else {
		if (u2 != 0 && d1 != 0 && d2 != 0 && c1 != 0 && c2 != 0 && m1 != 0 && m2 != 0 && u1 != 0){
		
			printf("(%d%d%d%d%d%d%d%d)\n",m1,m2,c1,c2,d1,d2,u1,u2);
			
		} else if (m1 != 0){
		
			printf("(%d%d%d%d%d%d%d%d)\n",m1,m2,c1,c2,d1,d2,u1,u2);
		
			
		} else if (d1 == 0 && d2 == 0 && c1 == 0 && c2 == 0 && m1 == 0 && m2 == 0 && u1 == 0 && u2 != 0){
		
			printf("(%d)\n",u2);
		
		} else if (d1 == 0 && d2 == 0 && c1 == 0 && c2 == 0 && m1 == 0 && m2 == 0 && u1 != 0){
	
			printf("(%d%d)\n",u1,u2);
			
		} else if (d1 == 0 && d2 != 0 && c1 == 0 && c2 == 0 && m1 == 0 && m2 == 0){
		
			printf("(%d%d%d)\n",d2,u1,u2);
		
		} else if (d1 != 0 && c1 == 0 && c2 == 0 && m1 == 0 && m2 == 0 ){
		
			printf("(%d%d%d%d)\n",d1,d2,u1,u2);
			
		} else if (c1 == 0 && c2 != 0 && m1 == 0 && m2 == 0){
		
			printf("(%d%d%d%d%d)\n",c2,d1,d2,u1,u2);
			
		
		}else if ( c1 != 0 && m1 == 0 && m2 == 0){
	
			printf("(%d%d%d%d%d%d)\n",c1,c2,d1,d2,u1,u2);
			
		}else if ( m1 == 0 && m2 != 0){
		
			printf("(%d%d%d%d%d%d%d)\n",m2, c1,c2,d1,d2,u1,u2);
		}
		
		
		
		
		
		
		
		
		
		
		
			
	}

}
