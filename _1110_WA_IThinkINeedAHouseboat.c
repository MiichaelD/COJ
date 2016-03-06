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
const double PI=3.1415926;

double radio(double i){
	//i=anoActual * 50, 2 porque es MEDIO circulo, PI=3.14
	return sqrt(i*2/PI);
}

int ano(int X, int Y){
	int num=1;
	double dist=sqrt((X*X)+(Y*Y));
	while(radio(num*50)<dist) 
			num++;
	return num;
}



int main(){
	int i,cases;
	scanf("%d",&cases);
	for(i=1;i<=cases;i++){
		float X,Y;
		scanf("%f%f",&X,&Y);
//TLE!! - printf("Property %d: This property will begin eroding in year %d.\n",i,ano(X,Y));
		printf("Property %d: This property will begin eroding in year %d.\n",i,(int)ceil(PI*(X*X+Y*Y)/100.0));
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
/*			EXPLICACIÓN
al ano el area aumenta 50 millas cuadradas 
i	=	ano
Ri 	=	Radio que traga el agua cada ano
dist=	distancia(radio) de 0,0 a x,y (casa al centro)

dist=	sqrt(X*X+Y*Y);

area circulo	=	PI*r*r/2
50i = 	PI*r*r/2 (pero como es medio circulo:)
50i*2=	PI*r*r  (despejamos R porqe nos interesa el radio)
Ri 	=	sqrt(100i/PI); con esta funcion encontramos el radio al finalizar el ano i;

hacemos igualdad en los 2 radios que tenemos para encontrar el ano en el qe el radio es igual

Ri 	=	dist

sqrt(100i/PI) = sqrt(X*X+Y*Y)
100i/PI = X*X+Y*Y
100i	= PI*(X*X+Y*Y)
i	= PI*(X*X+Y*Y)/100;   con estro encontramos el ano exacto en el agua alcanza la casa.

como nos lo da con exactitud (decimales) y nos interesa el final del ano truncamos hacia arriba:
ej. si al ano 19.625, el hogar fue alcanzado en el ano 19 y 1/16 de ano, es decir qe al terminar el ano
19 (osea empezando el ano 20) se alcanzo la casa, entonces se imprime 20

math ceil regresa el numero entero mayor al que recibe de parametro (redondea hacia arriba SIEMPRE)

*/