#include <cstdio>
#include <vector>
#include <iostream>

int main(){
  int museums, price;
  while (true) {
    std::cin >> museums;
    if (museums < 0) {
      break;
    }
    int times = 0, acumulator = 0;
    for (int m = 0; m < museums; ++m) {
      std::cin >> price;
      acumulator += price;
      if ((acumulator % 100) == 0){
        ++times;
      } 
    }
    std::cout << times << std::endl;
  }  
  return EXIT_SUCCESS;
}
