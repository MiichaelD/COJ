#include <algorithm>    // std::sort
#include <functional>   // std::greater
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

/**
 * Number theory: a number is divisible by 3 if the sum of digits adds to a
 * multiple of 3. A number is divisible by 30 with the same divisibility
 * condition but it should end with at least 1 zero.
*/
std::string findBiggest30Multiple(std::string &input) {
	int maxMultiple = -1;
	int zeroChars = 0;
  int charSum = 0;
	for (int i = 0; i < input.length(); ++i) {
		if (input.at(i) == '0') {
			++zeroChars;
		}
		charSum += input.at(i) - '0';
	}
	
	if (zeroChars < 1 || (charSum % 3) != 0) {
		return "-1";  // Multiples of 30 should end at 0.
	}
	std::sort(input.begin(), input.end(), std::greater<char>());
	return input;
}

int main(){
	std::string input;
	std::cin >> input;
	std::cout << findBiggest30Multiple(input) << std::endl;
}
