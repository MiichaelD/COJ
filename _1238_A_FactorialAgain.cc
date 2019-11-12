/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=1273
 *  Programmer: Michael Duarte
 *  Date:       November 11th 2019
 */

#include <algorithm> // std::sort
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <ctype.h>  // char related functions
#include <cmath>   // pow, floor

using namespace std;

static const int factorial[7] = {1, 1, 2, 6, 24, 120, 720};

void solve() {
  int number, sum;
  while (!cin.eof()) {
    cin >> number;
    if (number == 0) break;

    int index = 1, sum = 0; //, acum = 1;
    while (number != 0) {
      // acum *= index;
      sum += (number % 10) * factorial[index++];
      number /= 10;
    }
    cout << sum << endl;
  }
}

void solve1() {
  string number;
  while (!cin.eof()) {
    cin >> number;
    if (number.at(0) == '0') break;
    int sum = 0; //, acum = 1;
    for (int index = 1, endIndex = number.length() - 1;
         endIndex >= 0; ++index, --endIndex) {
      // acum *= index;
      sum += (number.at(endIndex) - '0') * factorial[index];
    }
    cout << sum << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return EXIT_SUCCESS;
}
