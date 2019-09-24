#include <iostream>

int main(){
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int cases;
  std::string input;
  std::cin >> cases;
  while (cases--) {
    std::cin >> input;
    std::cout << input;
    for (char c: input) {
      std::cout << '0';
    }
    std::cout << std::endl;
  }
  return EXIT_SUCCESS;
}
