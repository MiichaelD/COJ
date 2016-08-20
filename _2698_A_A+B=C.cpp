#include <cstdio>
#include <string>
#include <iostream>

int main(){
	std::string M;
	std::cin >> M;
	int i = 0;
	int counter = 0;
	for(;i<M.length();++i){
		counter+= M.at(i)-'@'; // '@' is the character before 'A'.
	}
	printf("%d\n",counter);
}
