//http://coj.uci.cu/24h/problem.xhtml?pid=2300

#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <utility>

using namespace std;

int waitTimeForChar(char c){
	int num;
	static int offset = 2;
	if (c < 'S'){
		num = (c - 'A') / 3 + 1;
	} else if ( c == 'S'){
		num =  6;
	} else if (c < 'Z'){
		num = (c - 'A' - 1) / 3 + 1;
	} else {
		num = 8;
	}

	return num + offset;
}

int waitTimeForStr(const string &input){
	int time = 0;
	for (char c : input){
		time += waitTimeForChar(c);
	}
	return time;
}


int main(){
	std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
	string input;
	cin >> input;
	cout << waitTimeForStr(input) << endl;
	
}
