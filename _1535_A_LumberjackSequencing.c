#include <stdio.h>

main(){
	int cases,a, b , i, res;
	scanf("%d",&cases);
	printf("Lumberjacks:\n");
	while( cases-- ){
	
		res = 1;
		scanf ("%d %d",&a, &b);
		
		if( a < b){
			for ( i =2 ; i < 10; i ++ ) {
				scanf (" %d", &a) ;
				if( a < b){
					res = 0;
				}
				b = a;
			} 
		}
		else {
			for ( i =2 ; i < 10; i ++ ) {
				scanf (" %d", &a) ;
				if( a > b){
					res = 0;
				}
				b = a;
			} 
		}
		if( res ) 
			printf("Ordered\n");		
		else 
			printf("Unordered\n");		
	}
}

/**
3
13 25 39 40 55 62 68 77 88 95
88 62 77 20 40 10 99 56 45 36
91 78 61 59 54 49 43 33 26 18


*/
