/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=1376
 *  Programmer: Michael Duarte
 *  Date:       November 8th 2019
 * 
 * Best solution: Using std::next_permutation: http://coj.uci.cu/24h/submission.xhtml?id=1130202
 * https://en.cppreference.com/w/cpp/algorithm/next_permutation
 */

#include <algorithm> // std::sort
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <ctype.h>  // char related functions
#include <cmath>   // pow

using namespace std;

void print(const vector<char> &number) {
  for (int j = 0; j < number.size(); ++j) {
    cout << number[j];
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  char c;
  vector<char> number;
  while(!cin.eof()){
    c = getchar();
    if (c == EOF || c == '\n' || c == '\r') break;
    number.push_back(c);
  }
  for (int i = number.size() - 1; i > 0; --i) {
    int minGreater = 10;
    int minGreaterInd = -1;
    for (int j = i; j < number.size(); ++j) {
      int delta = number[j] - number[i-1];
      if (delta > 0 && delta < minGreater) {
        minGreater = number[j] - number[i-1];
        minGreaterInd = j;
      }
    }
    if (minGreaterInd > 0) {
      int aux = number[minGreaterInd];
      number[minGreaterInd] = number[i-1];
      number[i-1] = aux;
      sort((number.begin()+i), number.end());
      print(number);
      return EXIT_SUCCESS;
    }
  }
  // No solution found
  cout << '0' << endl;
  return EXIT_SUCCESS;
}
