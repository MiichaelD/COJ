#include <cstdio>
#include <vector>
#include <iostream>

int main(){
  int x2, x5, x7, max = -1;

  for (int k = 0 ; k < 4; ++k) {
    std::cin >> x2 >> x5 >> x7;
    int scoops = (x2 * 2) + (x5 * 5) + (x7 * 7);
    if (scoops > max) {
      max = scoops;
    }
  }
  std::cout << max << std::endl;
}
