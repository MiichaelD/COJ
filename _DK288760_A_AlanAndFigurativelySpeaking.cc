/**
 *  Problem:    https://codeforces.com/group/BQ6WfEWeXy/contest/288760/problem/A
 *  Programmer: Michael Duarte
 *  Date:       July 31st 2020
 */

#include <algorithm> // std::sort
#include <iostream>
#include <ctype.h>  // char related functions
#include <cmath>   // pow, floor
#include <deque>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


void solve() {
  string input;
  char outputChar;
  cin >> input;
  for (char c : input) {
    switch (c) {
      case 'o':
      case 'O': outputChar = '0'; break;
      case 'i':
      case 'I': outputChar = '1'; break;
      case 'z':
      case 'Z': outputChar = '2'; break;
      case 'e':
      case 'E': outputChar = '3'; break;
      case 'a':
      case 'A': outputChar = '4'; break;
      case 's':
      case 'S': outputChar = '5'; break;
      case 'g':
      case 'G': outputChar = '6'; break;
      case 't':
      case 'T': outputChar = '7'; break;
      case 'b':
      case 'B': outputChar = '8'; break;
      default: outputChar = c;break;
    }
    cout << outputChar;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return EXIT_SUCCESS;
}
