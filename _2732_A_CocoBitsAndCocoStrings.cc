/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=2732
 *  Programmer: Michael Duarte
 *  Date:       November 8th 2019
 */

#include <algorithm> // std::sort
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <ctype.h>  // char related functions

using namespace std;

string inverse(const string &input) {
  stringstream ss;
  for (char c : input) {
    ss << (char) (islower(c) ?  toupper(c) : tolower(c));
  }
  return ss.str();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string input;
  int cases;
  cin >> cases;
  while (cases--) {
    cin >> input;
    cout << inverse(input) << endl;
  }
  return EXIT_SUCCESS;
}