//http://coj.uci.cu/24h/problem.xhtml?pid=2979

#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>

using namespace std;

int main(){
  std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
  cin.tie(NULL);

  int N, num, ordered, aux;
  cin >> N;
  while(N--){
    cin >> num;
    ordered = 0;
    for (int i = 1; i <= num; ++i){
      cin >> aux;
      if (i == aux)
        ++ordered;
    }
    cout << (num - ordered) << endl;
  }
  return EXIT_SUCCESS;
}
