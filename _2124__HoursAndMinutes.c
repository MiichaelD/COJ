#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	

	int main(){
		int input,n,ar[181];
		memset(ar,0,sizeof(ar));
		for(n=0;n<181;n++){
			ar[(n*72-n*6)%181]++;
		}		
		
		for(n=0;n<181;n++){
			printf("%d= %d\n",n,ar[n]);
		}
		/*while(scanf("%d",&input) != EOF){
			if(ar[input])
				printf("Y");
			else
				printf("N");
		}*/
	}
