#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>


int nextStopPassengers(int passengers) {
	return 2 * passengers + 1;
}

int main(){
	int cases;
	std::string correct, changed;

	std::cin >> cases;
	for (int k = 0 ; k < cases; ++k) {
		std::cin >> correct >> changed;
		int differences = 0;
		for (int i = 0 ; i < correct.length(); ++i) {
			if (correct.at(i) != changed.at(i)) {
				++differences;
			}
		}
		std::cout << differences << std::endl;
	}
}
