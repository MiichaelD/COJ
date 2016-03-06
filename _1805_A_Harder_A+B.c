/*

	Programador: 	Michael Duarte
	Fecha: 			17/Noviembre/2012
	Problema:		http://coj.uci.cu/24h/problem.xhtml?abb=1805
*/

#include <stdio.h>


int main(){
	unsigned long long int a,b;
	scanf("%lld %lld",&a,&b);
	printf("%lld",(a+a+b+b));
	return 0;
}