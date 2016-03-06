#include <stdio.h>
#include <stdlib.h>
#define MAXFLOWERS 51

main(){
	int flowers, ind, lowerImpair = 100, counter = 0, aux;
	
	scanf("%d",&flowers);
	
	scanf("%d",&aux);
	if( aux % 2 )
		lowerImpair=aux;
	counter+=aux;
	
	
	//printf(" flowers : %d, 1st: %d, lowerImp: %d\n\n",flowers,aux,lowerImpair);
	for (ind = 1 ; ind < flowers; ind++){
		scanf(" %d",&aux);
		counter+=aux;
		if( aux % 2  && lowerImpair > aux){
			lowerImpair=aux;
		}
	} 
	
	//printf("counter: %d, lower: %d\n",counter,lowerImpair);
	if( counter % 2 )
		printf("%d\n",counter);
	else if( lowerImpair == 100 )
		printf("-1\n");
	else
		printf("%d\n",counter-lowerImpair);
	
}
/**
3
1 5 6



*/