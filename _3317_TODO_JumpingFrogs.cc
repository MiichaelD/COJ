/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=3317
 *  Programmer: Michael Duarte
 *  Date:       June 19th 2020
 *  Run:        g++ -std=c++11 -o main _3317_TODO_JumpingFrogs.cc; cat _3317_input.txt | ./main
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

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const &pair) const {
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);
		return h1 ^ h2;
	}
};

unsigned long long amountOfWaysToCross(
    unsigned int steps,
    unordered_map<pair<int,int>, unsigned long long, pair_hash> &memo,
    int index = 0,
    int speed = 1) {
  unsigned long long output = 0L;
  if (index >= steps) {
    return 1L;
  }  
  auto idPair = make_pair(index, speed);
  if (memo.find(idPair) != memo.end()) {
    return memo[idPair];
  }
  output += amountOfWaysToCross(steps, memo, index + speed + 1, speed + 1);  // Increase by 1
  output += amountOfWaysToCross(steps, memo, index + speed + 2, speed + 2);  // Increase by 2

  memo[idPair] = output;
  return false;
}


unsigned long long numberOfWaysToCrossPath(unsigned int steps) {
  // TODO(michaelduarte): solve problem, similar to 1 FB interview question.
  unordered_map<pair<int,int>, unsigned long long, pair_hash> memo;
  unsigned long long output = amountOfWaysToCross(steps, memo);
  return output;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  unsigned int cases, steps;
  
  cin >> cases;
  while (cases--) {
    cin >> steps;
    cout << (numberOfWaysToCrossPath(steps) % 1000000007L) << endl;
  }
  return EXIT_SUCCESS;
}
