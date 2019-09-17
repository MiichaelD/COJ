#include <cstdio>
#include <cmath>
#include <iostream>

int main(){
	float r,g,b;
	std::cin >> r >> g >> b;
	std::cout << std::round((r + g + b) / 3) << std::endl;
}
