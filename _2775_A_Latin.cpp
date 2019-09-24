#include <cstdio>
#include <string>
#include <iostream>


int main(){
  int cases;
  std::string input;

  std::cin >> cases;
  for (int k = 0 ; k < cases; ++k) {
    std::cin >> input;
    if (input[0] == 'a' || input[0] == 'e' || input[0] == 'i' || input[0] == 'o'
        || input[0] == 'u') {
        std::cout << input << "cow" << std::endl;
    } else {
      std::cout << input.substr(1) << input[0] << "ow" << std::endl;
    }
  }
}
