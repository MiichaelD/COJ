/*

	Programador: 	Michael Duarte
	Fecha: 			20/Noviembre/2012
	Problema:		http://coj.uci.cu/virtual/vproblem.xhtml?abb=1352
*/

#include <stdio.h>
#include <memory.h>
#include <math.h>

#define M 1001

int arr[M];

int main(){
	int i,cases,aux;
	scanf("%d",&cases);
	while(cases != 0){
		memset(arr,0,sizeof(arr));
		for(i=1;i<=cases;i++){
			scanf(" %d",&aux);
			arr[i]=aux;
		}
		arr[cases+1]=0;
		
		aux=0;
		for(i=1;i<=cases;i++){
			if(arr[i]!=i){
				aux=arr[i];
				if(arr[aux] == i)
					printf("%d %d\n",i,aux);
				else 
					printf("0 0\n");
				break;
			}
		}
		if(aux == 0){
			printf("0 0\n");
		}
		scanf("%d",&cases);		
	}
}
/*input:
8
1 6 5 4 3 2 7 8
4
2 3 4 1
4
1 2 3 4
0

*/