//http://coj.uci.cu/24h/problem.xhtml?pid=1252

#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <string.h>

using namespace std;

const int MAX_LEN = 80;
const int MAX_SIZE = 255;


char getLastChar(char c){
	switch (c){
		case ' ': return '0';
		case '!': return '1';
		case '$': return '4';
		case '%': return '5';
		case '(': return '8';
		case ')': return '9';
		case '*': return 'a';
		default:
			break;
	}
	return c;
}

bool isSpecial(char c){
	switch (c){
		case ' ': 
		case '!': 
		case '$': 
		case '%': 
		case '(': 
		case ')': 
		case '*':
			return true;
		
		default:
			break;
		
	}
	return false;
}

void urify(char *str){
	int i = 0, size = 0, specials = 0;
	for (; i < MAX_LEN && str[i] != '\0'; ++i){
		if (isSpecial(str[i])){
			++specials;
		}
	}

	if (specials == 0) return;

	size = i + (specials * 2);
	str[size] = '\0';
	for (--i, --size; specials && i < size && i >= 0; --i, --size){
		char c = str[i];
		str[size] = getLastChar(c);
		if (isSpecial(c)){
			str[--size] = '2';
			str[--size] = '%';
			--specials;
		}
	}
}

void print(const char *str){
	for (int i = 0 ; i < MAX_SIZE && str[i] != '\0'; ++i){
		cout << str[i];
	}
	cout << endl;
}

int main(){
	std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
	cin.tie(NULL);

	char str[MAX_SIZE] = {'\0'};
	while (true){
		cin.getline(str,MAX_LEN);
		if (str[0] == '#') break;
		urify(str);
		print(str);
	}
	return EXIT_SUCCESS;
}