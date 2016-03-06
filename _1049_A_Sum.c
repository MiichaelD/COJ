/*

	Programador: 	Michael Duarte
	Fecha: 			17/Noviembre/2012
	Problema:		http://coj.uci.cu/24h/problem.xhtml?abb=1049
*/

#include <stdio.h>

int sum(int i){
	if(i>=0)
		return ((i+1)*i)/2;
	return (1+((i-1)*(-i)/2));
}

int main(){
	int num;
	scanf("%d",&num);
	printf("%d\n",sum(num));
}