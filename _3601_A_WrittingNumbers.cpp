//http://coj.uci.cu/24h/problem.xhtml?pid=3601

#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <utility>

using namespace std;

string englishNums [] = {"zero","one","two","three","four","five","six","seven",
						"eight","nine","ten","eleven","twelve"};


int main(){
	std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
	cin.tie(NULL);

	int N, aux;
	cin >> N;
	while(N--){
		cin >> aux;
		cout << englishNums[aux] << endl;
	}
	return EXIT_SUCCESS;
}
