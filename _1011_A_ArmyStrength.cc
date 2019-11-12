/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=1011
 *  Programmer: Michael Duarte
 *  Date:       November 12th 2019
 */

#include <algorithm> // std::sort
#include <iostream>
#include <ctype.h>  // char related functions
#include <cmath>   // pow, floor
#include <deque>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void populateArmy(int amount, deque<int> &army) {
  int aux;
  for (int i = 0 ; i < amount; ++i) {
    cin >> aux;
    army.push_back(aux);
  }
  sort(army.begin(), army.end());
}

void solve() {
  int cases, godArmyN, mechaGodArmyN;
  cin >> cases;
  while (cases--) {
    deque<int> godArmy, mechaGodArmy;
    cin >> godArmyN >> mechaGodArmyN;
    populateArmy(godArmyN, godArmy);
    populateArmy(mechaGodArmyN, mechaGodArmy);

    while (godArmy.size() && mechaGodArmy.size()) {
      // cout << *godArmy.begin() << " < " << *mechaGodArmy.begin() << " ? ";
      if (*godArmy.begin() < *mechaGodArmy.begin()) {
        godArmy.pop_front();
        // cout <<  " YES " << endl;
      } else {
        mechaGodArmy.pop_front();
        // cout << " NO " << endl; 
      }
    }
    if (godArmy.empty() && mechaGodArmy.empty()) {
      cout << "uncertain" << endl;
    }else {
      cout << (godArmy.size() ? "Godzilla" : "MechaGodzilla") << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return EXIT_SUCCESS;
}
