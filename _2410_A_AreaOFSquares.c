#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

double getArea(double len, int squares){
	return len*len/pow(2,squares-1)+pow(10,-6);
}

int main(){
    unsigned int cases, k=0, len, squ;

    scanf("%d",&cases);
   
    while( k++ < cases){
        scanf("%d %d",&len, &squ);
        printf("Case #%d: %.2f\n",k,getArea(len, squ));
    }
   
    return    EXIT_SUCCESS;
}

