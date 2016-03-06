/*

	Programador: 	Michael Duarte
	Fecha: 			17/Noviembre/2012
	Problema:		http://coj.uci.cu/24h/problem.xhtml?abb=1110
	
	
input:
2
1.0 1.0
25.0 0.0

*/

#include <stdio.h>
#include <math.h>

double radio(double i){
	return sqrt(i*2/3.14);
}

int main(){
	int i,cases;
	scanf("%d",&cases);
	for(i=1;i<=cases;i++){
		float X,Y;
		int num=1;
		scanf("%f%f",&X,&Y);
		double dist=sqrt((X*X)+(Y*Y));
		while(radio(num*50)<dist) 
			num++;
		printf("Property %d: This property will begin eroding in year %d.\n",i,num);
	}
}