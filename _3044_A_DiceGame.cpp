#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int,int>> rollResults;
  int a, b, accum = 0, rolls = 4;
  for (int r = 0; r < rolls; ++r) {
    std::cin >> a >> b;
    rollResults.emplace_back(make_pair(a, b));
  }
  for (int r = 0; r < rolls / 2; ++r) {
    accum += (rollResults[r].first - rollResults[r+2].first)
        + (rollResults[r].second - rollResults[r+2].second);
  }
  cout << (accum == 0 ? "Tie" : (accum < 0 ? "Emma" : "Gunnar")) << endl;
  return EXIT_SUCCESS;
}
