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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int cases;
  string input;
  int buckets[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cin >> cases;
  while (cases--) {
    cin >> input >> input;
    bool foundDelimiter = false;
    int number = 0;
    for (int i = 0; i < input.length(); ++i) {
      char c = input.at(i);
      if (foundDelimiter && isdigit(c)) {
        number *= 10;
        number += c - '0';
      }
      if (c == '/') { 
        if (foundDelimiter) {
          break;
        } else {
          foundDelimiter = true;
        }
      }
    }
    ++buckets[number];
  }
  for (int i = 1; i < 13; ++i) {
    cout << i << " " << buckets[i] << endl;
  }
  return EXIT_SUCCESS;
}
