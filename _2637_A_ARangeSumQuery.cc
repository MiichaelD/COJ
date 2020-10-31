/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=2637
 *  Programmer: Michael Duarte
 *  Date:       June 19th 2020
 *  Run:        g++ -std=c++11 -o main _2637_A_ARangeSumQuery.cc; cat _2637_input.txt | ./main
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
  unsigned int aux, n, q, q1, q2;
  
  cin >> cases;
  while (cases--) {
    cin >> n >> q;
    vector<unsigned long long> vec;
    vector<unsigned long long> acumVec;
    vec.reserve(n);
    unsigned long long acumAux = 0;
    for (unsigned int i = 0; i < n; ++i) {
      cin >> aux;
      acumAux += aux;
      vec.push_back(aux);
      acumVec.push_back(acumAux);
      // cout << "Aux: " << aux << endl;
    }
    for (unsigned int i = 0; i < q; ++i) {
      cin >> q1 >> q2;
      // cout << q1 << "\t" << q2 << endl;
      cout << (acumVec[q2] - acumVec[q1-1]) << endl;
    }
    if (cases) {
      cout << endl;
    }
  }
  return EXIT_SUCCESS;
}
