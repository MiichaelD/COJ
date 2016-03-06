#include <stdio.h>

main(){
	int cases,n,nums,in,odd;
	
	scanf("%d",&cases);
	
	while( cases-- ){
		scanf("%d",&n);
		nums = n;
		odd = 0;
		while( n-- ) {
			scanf("%d",&in);
			if(in % 2){
				odd++;
			}
		}
		printf("%d even and %d odd.\n",nums-odd, odd);		
	}
}

