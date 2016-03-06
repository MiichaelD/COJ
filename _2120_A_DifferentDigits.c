//floor(log10(abs(the_integer))) + 1; - conocer cuantos digitos tiene un numero
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	int main(){
		int i,n,m,ar[10],aux,aux2,counter;
		char read[15];
		while(fgets(read,15,stdin) != NULL){
			sscanf(read,"%d%d",&n,&m);
			counter=0;			
			for(i=n;i<=m;i++){
				memset(ar,0,sizeof(ar));
				aux=i;
				counter++;
				while(aux){
					if(ar[aux%10]++){
						counter--;
						break;
					}
					aux/=10;
				}
			}				
			printf("%d\n",counter);
		}		
	}
