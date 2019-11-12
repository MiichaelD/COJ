/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=1024
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

vector<float> lengthMemo;

const float MAX_CARD_LEN = 5.21f;

void fillMemo() {
  lengthMemo.push_back(0);
  for (int i = 2; lengthMemo.back() < MAX_CARD_LEN; ++i) {
    float val = lengthMemo.back() + (1.0f / i);
    // cout << "Card #" << i-1 << ": " << val << endl;
    lengthMemo.push_back(val);
  }
}

int bisecAmountOfCards(float target, int low, int high) {
  int mid = (low + high) >> 1;
  if (target <= lengthMemo[mid] && (target > lengthMemo[mid-1])) {
    return mid;
  }
  if (target > lengthMemo[mid]) {
    return bisecAmountOfCards(target, mid + 1, high);
  }
  if (target < lengthMemo[mid]) {
    return bisecAmountOfCards(target, low, mid);
  }
  cout << "\tLooking for target: " << target << " between: " << low << " < " << mid << " > ";
  cout << high <<  " Failed! " << endl;
  return -1;
}

int linearAmountOfCards(float target) {
  int i = 1;
  if (target > 5.0f) i = 227;
  if (target > 4.6f) i = 152;
  if (target > 4.0f) i = 83;
  if (target > 3.0f) i = 31;
  for (int i = 1; i < lengthMemo.size(); ++i) {
    // if ((target - lengthMemo[i]) < std::numeric_limits<float>::epsilon()) {
    if (target <= lengthMemo[i]) {
      return i;
    }
  }
  return -1;
}

inline int minAmountOFCards(const float cardsLength) {
  int solution = bisecAmountOfCards(cardsLength, 0, lengthMemo.size());
  return solution;
}

void test() {
  for (float i = 45; i < 520; ++i) {
    float target = i / 100;
    int sol1 = minAmountOFCards(target);
    int sol2 = linearAmountOfCards(target);
    if (sol1 != sol2) {
      cout << "bisec = " << sol1 << ", linear: " << sol2 << " for target: " << target << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  float input;
  fillMemo();
  // test();
  while (!cin.eof()) {
    cin >> input;
    if (input == 0.0f) {
      break;
    }
    cout << linearAmountOfCards(input) << " card(s)" << endl;
  }
  return EXIT_SUCCESS;
}
