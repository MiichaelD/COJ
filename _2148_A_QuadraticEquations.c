#include <stdio.h>

int main(){
	
	int k,a,b,c;
	
	scanf("%d",&k);
	
	while( k--){
		scanf("%d %d %d",&a,&b,&c);
		if( 4*a*c > b*b )
			printf("NO\n");
		else
			printf("SI\n");
	}	
}
/*input:
2
1 9 10
1 3 10

*/