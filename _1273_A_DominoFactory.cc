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
  int maxDots, L, W, cases;
  cin >> cases;
  while (cases--) {
    cin >> maxDots >> L >> W;
    int maxPieces = ((maxDots + 1) * (maxDots + 2)) / 2; // extra one for the 0-dot pieces.
    // int maxPieces = ((maxDots * maxDots) * (3 * maxDots) + 2) / 2;
    cout << maxPieces * L * W << endl;
  }
  return EXIT_SUCCESS;
}
