#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

	int main(){
		int teams, damaged, reserve, d, r, k;
		int arr[12];
		
		for(k=0;k<12;k++)
			arr[k]=1;
		
		scanf("%d %d %d",&teams,&damaged,&reserve);
		
				
		for(d=0;d<damaged;d++){
			if(d < damaged-1)
				scanf("%d ",&k);
			else
				scanf("%d",&k);
				
			arr[k]=0;
		}
		
		for(r=0;r<reserve;r++){
			if(r < reserve-1)
				scanf("%d ",&k);
			else
				scanf("%d",&k);
				
			if( ++arr[k] == 1 )
				damaged--;
		}
		
		for(k = 1; k <= teams; k++){
			if(!arr[k]){
				//printf("team %d is missing kayacs\n",k);
				if( arr[k-1] == 2 ){
					//printf("\tteam %d lended kayacs\n",k-1);
					arr[k-1]--;
					arr[k]++;
					damaged --;
				}
				else if( arr[k+1] == 2 ){
					//printf("\tteam %d lended kayacs\n",k+1);
					arr[k+1]--;
					arr[k]++;
					damaged --;
				}
				
			}
		}
		
		
		printf("%d\n",damaged);
		return	EXIT_SUCCESS;
	}

	/*
5 2 1
2 3
3


	
*/