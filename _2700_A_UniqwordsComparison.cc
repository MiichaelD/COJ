/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=2700
 *  Programmer: Michael Duarte
 *  Date:       November 8th 2019
 */

#include <algorithm> // std::sort
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <memory>
#include <ctype.h>  // char related functions

using namespace std;

unordered_set<char> fromStrToSet(const string &input) {
  unordered_set<char> output;
  for (char c : input) {
    output.insert(c);
  }
  return output;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string input1, input2;
  cin >> input1 >> input2;
  unordered_set<char> set1 = fromStrToSet(input1);
  unordered_set<char> set2 = fromStrToSet(input2);
  cout << "First:";
  for (char c : input1) {
    if (set2.find(c) == set2.end()) {
      cout << c;
    }
  }
  cout << endl << "Second:";
  for (char c : input2) {
    if (set1.find(c) == set1.end()) {
      cout << c;
    }
  }
  cout << endl << "First&Second:";
  for (char c : input2) {
    if (set1.find(c) != set1.end()) {
      cout << c;
    }
  }
  cout << endl;
  return EXIT_SUCCESS;
}