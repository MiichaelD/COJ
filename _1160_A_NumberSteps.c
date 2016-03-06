#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001
main(){
	
	int i, j, k;
	
	/*unsigned long arr[MAX][MAX];
	unsigned long number;
	for (i =0 ;i < MAX; i ++)
		for(j=0; j < MAX; j++)
			arr[i][j] = 0;
	
	i = 0;
	j = 0;
	number = 0;
	
	while ( i < MAX && j < MAX){
		number++;
		if( number % 2 ){
			i++;
			j++;
		}
		else{
			if (number % 4){
				i++;
				j--;
			}
			else{
				i--;
				j++;
			}		
		}
		printf("%d = (%d,%d)\n",number,i,j);
		arr[i][j]=number;
	}
	*/
		
	scanf("%d",&k);
	
	while( k-- ){
		scanf("%d %d",&i, &j);
		if  ( i == j || i == j+2){
			if( i % 2 )
				printf("%d\n",i+j-1);
			else
				printf("%d\n",i+j);
		}
		else 
			printf("No Number\n");
	}	
}