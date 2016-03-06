#include <cstdio>
#include <cmath>
/*
input:  
2147483647
1.5
3

output: 
1431655764
1
2

relacion 3/2 : 1
entonces y = (int) 2x/3;

*/
int main(void){
		unsigned long n,i,cont=0,sum=0;
		scanf("%ld", &n);
		/*for(i=1;i<=n;i++)
			if( (sum=((sum+i) % 3) ) == 0)
				cont++;
		printf("%d\n",cont);
		*/
		printf("%ld\n",(long)(floor(n/1.5)));
		
		return 0;
}
