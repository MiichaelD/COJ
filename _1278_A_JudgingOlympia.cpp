//http://coj.uci.cu/24h/problem.xhtml?pid=1278

#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <utility>

using namespace std;


int main(){
	float sum;
	int min, max;
	while(true){
		sum = 0.0;
		min = 10;
		max = 0;
		for (int i = 0, x = 0 ; i < 6; ++ i){
			scanf("%d",&x);
			sum += x;
			if ( x > max)
				max = x;
			if ( x < min)
				min = x;
		}
		if (sum == 0)
			break;
		sum -= min;
		sum -= max;

		printf("%g\n", sum / 4);
	}
}
