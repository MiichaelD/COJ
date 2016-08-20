//http://coj.uci.cu/24h/problem.xhtml?pid=3442

#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <utility>

using namespace std;

inline void printChars(const string &input, int A, int B){
	for (int i = A; i < B; ++i){
		cout << input[i];
	}
}

inline void printSpaces(int amount){
	for(int i = 0 ; i < amount ; ++i){
		cout << ' ';
	}
}

void printLine(const string &input, int spaces){
	size_t len = input.length();
	int chars = (len - spaces)/2;

	printChars(input, 0 , chars);
	printSpaces(spaces);
	printChars(input, spaces+chars, len);
	cout << endl;
}

void printDiamondCutout(const string &input){
	size_t len = input.length();
	if (len % 2 == 0){
		cout << "error" << endl;
		return;
	}
	int halfLen = len / 2;
	int spaces = 1;
	--len;

	cout << input << endl;
	for (int i = 1 ; i < len ; ++i){
		if ( i >= halfLen ){
			printLine(input, spaces);
			spaces -= 2;
		} else {
			printLine(input, spaces);
			spaces += 2;
		}
	}
	cout << input << endl;
}

int main(){
	std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
	string input;
	cin >> input;
	printDiamondCutout(input);
}
