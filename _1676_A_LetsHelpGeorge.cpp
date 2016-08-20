//http://coj.uci.cu/24h/problem.xhtml?pid=1676

#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
	cin.tie(NULL);

	uint64_t memoization[10001] = {0};
	// we could also optimize the solution by loading all the values in the array before
	// processing the input. This by: iterating from 1 to MAXN: memoization[N] = memoization[N-1] +N*N;

	// Later I found out that this solution can be minimized to: N*(N+1)*(2*N+1)/6


	int N, cases = 0;
	memoization[1] = 1;
	while(true){
		cin >> N;
		if (N == 0)
			break;

		if (memoization[N] == 0) {
			for(int i = 1 ; i <= N; ++i){
				memoization[N] += i*i;
				// partial optimization if we are asked by a new N less than currentN
				// the value will be already saved.
				memoization[i] = memoization[N]; 
			}
		}
		cout << "Case "<< ++cases<<":\nn = "<<N<<", diamonds = "<<memoization[N]<<endl; 
	}
	return EXIT_SUCCESS;
}
