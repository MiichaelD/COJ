#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n1,n2,n3,aux;
	char c[4];
	scanf("%d %d %d",&n1,&n2,&n3);
	while (1)
	if (n1 < n2){
		if(n2 <n3){
		 break; 
		}
		else {
			aux = n2;
			n2 = n3;
			n3 = aux;
		}
	}else{
		if( n1 < n3){
			aux = n2;
			n2 = n1;
			n1 = aux;
		}
		else{
			if(n2 < n3){
				aux = n2;
				n2 = n3;
				n3 = n1;
				n1 = aux;
			}
			else{
				aux = n1;
				n1 = n3;
				n3 = aux;
			}
		}
	}
	
	
	scanf("%s",c);
	
	switch(c[0]){
		case 'A':
		printf("%d ",n1);
		break;
		
		case 'B':
		printf("%d ",n2);
		break;
		
		case 'C':
		printf("%d ",n3);
		break;
	}
	
	switch(c[1]){
		case 'A':
		printf("%d ",n1);
		break;
		
		case 'B':
		printf("%d ",n2);
		break;
		
		case 'C':
		printf("%d ",n3);
		break;
	}
	
	switch(c[2]){
		case 'A':
		printf("%d\n",n1);
		break;
		
		case 'B':
		printf("%d\n",n2);
		break;
		
		case 'C':
		printf("%d\n",n3);
		break;
		
	
	}
	
	
	
}