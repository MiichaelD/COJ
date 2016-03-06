/*

	Programador: 	Michael Duarte
	Fecha: 			08/Enero/2013
	Problema:		http://coj.uci.cu/24h/problem.xhtml?abb=1830
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	unsigned long  N,U,Q,i,j,ind,k,u,v;
	unsigned long long arr[1000001];
	unsigned int query;

void add(unsigned long index, unsigned long k){
	arr[index]+=k+1;
	if(index>0)
	arr[index-1]+=k;
	if(index<N)
	arr[index+1]+=k;
}


int main(){
	memset(arr,0,sizeof(arr));
	scanf("%ld %ld %ld",&N,&U,&Q);
	for(i=0;i<U;i++){
		scanf("%ld %ld",&ind,&k);
		add(ind,k%10000);
	}
	for(i=0;i<Q;i++){
		query=0;
		scanf("%ld %ld",&u,&v);
		for(j=u;j<=v;j++){
			query+=arr[j]%10000;
		}
		printf("%d\n",query);
	}
	return 0;
}
/*
6 2 2
3 6
4 7
4 6
1 6



*/