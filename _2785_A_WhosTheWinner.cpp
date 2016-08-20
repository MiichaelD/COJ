//http://coj.uci.cu/24h/problem.xhtml?pid=2785

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
	std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
	cin.tie(NULL);

	float sum;
	int N, aux;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		scanf("%d", &aux);
		sum += aux; 
	}
	printf("%.2f\n", sum / N);
}
