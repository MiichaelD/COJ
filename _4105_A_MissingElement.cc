/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=4105
 *  Programmer: Michael Duarte
 *  Date:       November 12th 2019
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

void solve() {
  long N, aux;
  unordered_set<int> numberSet;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    if (numberSet.find(i) == numberSet.end()) {
      cout << i << endl;
    }
  }
  for (int i = 1 ; i < N; ++i) {
    cin >> aux;
    numberSet.insert(aux);
  }
  for (int i = 1; i <= N; ++i) {
    if (numberSet.find(i) == numberSet.end()) {
      cout << i << endl;
    }
  }
}

void solve1() {
  long N, aux;
  unordered_set<int> numberSet;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    numberSet.insert(i);
  }
  for (int i = 1 ; i < N; ++i) {
    cin >> aux;
    numberSet.erase(aux);
  }
  cout << *numberSet.begin() << endl;
}

void solve2() {
  vector<unsigned long long int> vec(156251, 0); // (10,000,000 / 64) + 1
  const int LIMIT = 64; // 64 bits
  long N = 64, aux;
  // cin >> N;
  int missing = -1;
  // for (int i = 1 ; i < N; ++i) {
  for (int i = 1 ; i <= N; ++i) {
    // cin >> aux;
    aux = i;
    if (aux == missing) { 
      cout << "Missing: " << missing << endl;
      continue;
    }
    --aux; // start in index 0
    int index = aux / LIMIT;
    int bit = aux % LIMIT;
    vec[index] |= (1 << bit);
    // cout << "n = " << aux << " in index " << index << " and bit " << bit << endl;
  }
  for (int i = 0 ; i <= (N / LIMIT); ++i) {
    cout << "index " << i << " = " << vec[i] << endl;
    if (vec[i] <= UINT64_MAX) {
      // cout << "index " << i << " = " << vec[i] << endl;
      for (int j = 0; j < LIMIT; ++j) {
        if ((vec[i] & (1ull << j)) == 0) {
          cout << (i * 64) + j + 1 << endl;
          return;
        }
      }
    }
  }
}

void solve3() {
  long N, sum;
  int aux;
  cin >> N;
  sum = N * (N + 1) / 2;
  for (int i = 1 ; i < N; ++i) {
    cin >> aux;
    sum -= aux;
  }
  cout << sum << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve3();
  return EXIT_SUCCESS;
}
