//http://coj.uci.cu/24h/problem.xhtml?pid=2786

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

	int N;
	cin >> N;
	N *= N;
	cout<<(N/2)+(N%2)<<endl;
}
