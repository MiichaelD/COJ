#include <stdio.h>
#define MAX 5001

main(){
	int input, i, j;
	unsigned long res;
	
	/*int arr[MAX];
	arr[0]=1;
	for(i = 1; i < MAX; i++){
		arr[i] = i * 4 + (arr[i-1]); 
		printf("%d\n",arr[i]);
	}
	*/
	scanf("%d",&input);
			
	while( input-- ){
		scanf("%d",&i);
		res = 1;
		for(j = 1; j < i; j++){
			res += j * 4; 
		}
		printf("%d\n",res);
			
	}
}

