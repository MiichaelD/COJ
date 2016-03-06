#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>

int main(){
	int i = 0, input;
	float acum = 0.f;
	for(;i<30;++i){
		scanf("%d",&input);
		acum += input;
	}
	float average = acum / 30.0f;
	acum += average;
	acum = ceil(acum * 1000) / 1000; // round up to the 3rd digit
	printf("%.3f\n",acum);
}
