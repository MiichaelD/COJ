#include <cstdio>
#include <string>
#include <iostream>

int main(){
	int k;
	unsigned long long num;
	std::string input;
	scanf("%d",&k);
	while(k--){
		std::cin >> input;
		int i = 0;
		unsigned acum = 0;
		for (;i<input.length();++i){
			acum+=input.at(i)-'0';

			if(acum > 9){
				acum = (acum / 10) + (acum % 10);
			}
		}
		printf("%u\n",acum);
	}
}
