#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

//Wrong Answer  - http://coj.uci.cu/24h/problem.xhtml?abb=2410

double getArea(double len, int squares){
	/*while( --squares ){
		len = ( len / 2 );
		len *= len;
		len *= 2;
		len = sqrt( len );
	}
	return len * len;
	*/
	
	len *= len;
	while( --squares ) 
		len/=2;
	
	return ceil(len*100)/100;
	
}

	int main(){
		unsigned int cases, k=0, len, squ;
	
		scanf("%d",&cases);
		
		while( k++ < cases){
			scanf("%d %d",&len, &squ);
			printf("Case #%d: %.2f\n",k,getArea(len, squ));
		}
		
		return	EXIT_SUCCESS;
	}

	/*
8
2 1
1 2
5 1
5 2
5 3
5 4
5 5
5 6



Case #1: 4.00
Case #2: 0.50
*/