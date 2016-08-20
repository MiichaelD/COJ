// http://coj.uci.cu/24h/problem.xhtml?pid=2655 AVION
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main() {
	string input;
	vector<int> blimps;
	for (int i = 0; i < 5; ++i) {
		cin >> input;
		for (int j = 0; j < input.length() - 2; ++j) {
			if (input[j] == 'F') {
				if (input[j + 1] == 'B' && input[j + 2] == 'I') {
					blimps.push_back(i + 1);
					break;
				}
			}
		}
	}
	if (blimps.size()) {
		for (int i = 0; i < blimps.size() - 1; ++i) {
			cout << blimps[i] << ' ';
		}
		cout << blimps.back() << endl;
	}
	else {
		cout << "HE GOT AWAY!" << endl;
	}

}
