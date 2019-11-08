/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=2712
 *  Programmer: Michael Duarte
 *  Date:       November 8th 2019
 */

#include <algorithm> // std::sort
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <ctype.h>  // char related functions

using namespace std;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string ignored, input;
  int cases;
  cin >> cases;
  unordered_map<string, int> map;
  while (cases--) {
    cin >> ignored >> input;
    ++map[input];
  }
  cin >> cases;
  while (cases--) {
    cin >> ignored >> input;
    cout << map[input] << endl;
  }
  return EXIT_SUCCESS;
}