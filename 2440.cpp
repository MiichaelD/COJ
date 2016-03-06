#include <cstdio>
#include <string>
#include <iostream>

int main(){
	int k;
	std::string M, N;
	scanf("%d",&k);
	while(k--){
		std::cin >> M >> N;
		bool substring = (M.find(N) != std::string::npos && 
			M.find('T') != std::string::npos);
		if (substring)
			printf("Y\n");
		else printf("N\n");
	}
}
