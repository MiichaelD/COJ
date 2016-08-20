

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int k, n, c, m;
	int wrappers;
	int total;
	cin >> k;
	while (k--) {
		cin >> n >> c >> m;
		wrappers = n / c;
		total = wrappers;
		while (wrappers >= m) {
			int newChocolates = wrappers / m;
			total += newChocolates;
			wrappers = wrappers % m + newChocolates;
		}
		cout << total << endl;
	}
	return EXIT_SUCCESS;
}