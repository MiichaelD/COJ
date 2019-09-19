#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>

int minimumSteps(int current, int target, int steps = 0) {
  if (current == target) {
    return steps;
  } else if (target > current) { // increase by one
    return minimumSteps(current + 1, target, steps + 1);
  } else {  // decrease by half
    return (minimumSteps(current / 2, target, steps + 1));
  }
}

int main(){
  int cases, currentVol, targetVol;

  std::cin >> cases;
  for (int k = 0 ; k < cases; ++k) {
    std::cin >> currentVol >> targetVol;
    std::cout << minimumSteps(currentVol,targetVol) << std::endl;
  }
}
