#include <stdio.h>
#include <stdlib.h>

main(){
	int k, f, c;
	scanf("%d",&k);
	while( k-- ){
		scanf("%d %d",&f, &c);
		
		if( f % 2 ){//filas son IMPAR
			if( f > c){
				if ( c % 2 )//columnas son IMPARES
					printf("D\n");
				else
					printf("U\n");
			}
			else{
				printf("R\n");
			}
		}else{ //filas son PARes
			if( f > c){
				if( c % 2 )//columnas son IMPARES
					printf("D\n");
				else
					printf("U\n");
			}
			else{
				printf("L\n");
			}			
		}
	}
}