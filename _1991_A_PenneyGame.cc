/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=1991
 *  Programmer: Michael Duarte
 *  Date:       November 8th 2019
 */

#include <algorithm> // std::sort
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <ctype.h>  // char related functions
#include <cmath>  // pow

using namespace std;

constexpr  int SEQUENCE_LENGTH = 3;
const int COMBINATIONS = pow(2, SEQUENCE_LENGTH);

unordered_map<string, int> sequenceGenerator() {
  unordered_map<string, int> output;
  for (int i = 0 ; i < COMBINATIONS; ++i) {
    stringstream ssequence;
    ssequence << (i & 4 ? 'H' : 'T') << (i & 2 ? 'H' : 'T');
    ssequence << (i & 1 ? 'H' : 'T');
    output[ssequence.str()] =  i;
  }
  return output;
}

vector<int> findSequencesReps(const string &input, const unordered_map<string, int> &sequences) {
  vector<int> repetitions(COMBINATIONS, 0);
  for (int i = 0; i <= (input.length() - SEQUENCE_LENGTH); ++i) {
    string substr = input.substr(i, SEQUENCE_LENGTH);
    auto result = sequences.find(substr);
    if (result != sequences.end()) {
      ++repetitions[result->second];
    }
  }
  return repetitions;
}

void printReps(const vector<int> &reps) {
  for (int i = 0 ; i < reps.size(); ++i) {
    cout << " " << reps[i];
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int cases, dataset;
  string input;
  unordered_map<string, int> sequences = sequenceGenerator();
  cin >> cases;
  for (int i = 1; i <= cases; ++i) {
    cin >> dataset >> input;
    vector<int> result = findSequencesReps(input, sequences);
    cout << dataset;
    printReps(result);
  }
  return EXIT_SUCCESS;
}