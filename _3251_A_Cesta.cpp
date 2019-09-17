#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>


int nextStopPassengers(int passengers) {
	return 2 * passengers + 1;
}

int main(){
	int cases, input;
	std::vector<int> memo;
	memo.push_back(0);

	std::cin >> cases;
	for (int k = 0 ; k < cases; ++k) {
		std::cin >> input;
		while (input >= memo.size()) {
			memo.push_back(nextStopPassengers(memo[memo.size() - 1]));
		}
		std::cout << memo[input] << std::endl;
	}
}
