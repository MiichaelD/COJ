//http://coj.uci.cu/24h/problem.xhtml?pid=2769
#include <iostream>

using namespace std;


int main(){
	// http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cout << i <<": I am participating in the Engineer's day." << endl;
	}
	return EXIT_SUCCESS;
}