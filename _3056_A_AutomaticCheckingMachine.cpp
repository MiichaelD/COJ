//http://coj.uci.cu/24h/problem.xhtml?pid=3056

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

	int arrA[5];
	int b, i;
	for(i = 0 ; i < 5; ++i){
		cin >> arrA[i];
	}
	for(i = 0 ; i < 5; ++i){
		cin >> b;
		if ((arrA[i] ^ b) == 0){
			cout << "N" << endl;
			break;
		}
	}
	if (i == 5)
		cout << "Y" << endl;
	return EXIT_SUCCESS;
}
