#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int main(){
		int input,n,ar[181];
		memset(ar,0,sizeof(ar));
		for(n=0;n<33;n++){
			ar[(n-n/12)*6]++;
		}
		while(scanf("%d",&input) != EOF){
			if(ar[input])
				printf("Y\n");
			else
				printf("N\n");
		}
	}
