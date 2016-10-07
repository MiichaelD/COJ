//http://coj.uci.cu/24h/problem.xhtml?pid=1681

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

	double A,B,C, BB, AC4;
	cin >> A >> B >> C;

	BB = B * B;
	AC4 = 4 * A * C;
	cout << (BB >= AC4? "YES" : "NO") << endl;
	return EXIT_SUCCESS;
}