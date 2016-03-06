#include <stdio.h>
#include <memory.h>
//http://coj.uci.cu/24h/problem.xhtml?abb=1059
int main() {
	
	unsigned long int in,out=0,i;
	while(scanf("%ld",&in),in){
		char str[32];
		memset(str,0,32);
		out=0;
		printf("The parity of ");
		int idx=31;
		while(in){
			i=in&1;
			out+=i; 
			str[idx--]=i;
			in/=2;
		}
		while(idx<31)
			printf("%d",str[++idx]);
		printf(" is %ld (mod 2).\n",out);
	}
}
/*
1
2
10
21
0
0
0
*/