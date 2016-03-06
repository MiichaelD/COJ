#include <stdio.h>
#include <string.h>
#define MAXLETTERS 1100

int main(){
	
	int k, n, aux, c;
	unsigned int count;
	
	scanf("%d",&k);
	
	while( k-- ){
		count = 0;
		scanf("\n%d",&n);
		aux = n;
		while ( aux-- ){
			scanf("%d",&c);
			count += c;
		}

		if( count % n )
			printf("NO\n");
		else
			printf("YES\n");
	}	
}
/*input:
2

5
5
2
7
3
8

6
7
11
2
7
3
4


*/