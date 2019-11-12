/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=1006
 *  Programmer: Michael Duarte
 *  Date:       November 10th 2019
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


char decryptChar(char c) {
  if (isalpha(c)) {
    if (c == 'a' || c == 'A') {
      return c + ('z' - 'a');
    } else {
      return c - 1;
    }
  }
  return c;
}

string decrypt(const string &input) {
  stringstream output;
  for (char c : input) {
    output << decryptChar(c);
  }
  return output.str();
}

// working - creating just one full copy
string reassamble1(const string &input, size_t start, size_t end, size_t times = 0) {
  if (start >= end) {
    return input.substr(start,1);
  }
  size_t len = end - start;
  if (len < 3) {
    return input.substr(start, len);
  }
  bool isOddLen = len % 2;
  size_t half = (len / 2) + (isOddLen ? 1 : 0) + start;
  
  stringstream output;
  output << reassamble1(input, start + 1, half, times + 1);
  output << input.at(start);
  output << reassamble1(input, half, end, times + 1);
  return output.str();
}
string reassamble1(const string &input) {
  return reassamble1(input, 0, input.length());
}

//working - copying strings
string reassamble(const string &input) {
  size_t len = input.length();
  if (len < 3)  return input;
  bool isOddLen = len % 2;
  size_t half = (len / 2) + (isOddLen ? 1 : 0);
  
  stringstream output;
  output << reassamble(input.substr(1, half - 1));
  output << (input.at(0));
  output << reassamble(input.substr(half, len - half));
  return output.str();
}//

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string input, word;
  while (!cin.eof()) {
    getline(cin, input);
    input = decrypt(input);
    cout << reassamble(input) << endl;
  }
  return EXIT_SUCCESS;
}
