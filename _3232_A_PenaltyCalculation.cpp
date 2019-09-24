/**
 *Description:  In the forthcoming UCI Cup, COJ Development Team fears the possibility of the main
                structure of the site to go down. Therefore they have assigned many young programmers
                (you among them) to code backup modules, so if anything goes wrong during the contest,
                the competitors don’t get upset. 
                The task assigned to you is to calculate the penalty for a specific problem from a team.

                You will be given 1 <= N <= 100, the number of submissions, and for each one you will also
                know the minute 1 <= Mi <= 300 it was submitted and the judge verdict by its identifier
                which can be one of these:

                Verdict - Identifier
                    Wrong Answer - WA
                    Time Limit Exceeded – TLE
                    Runtime Error – RTE
                    Compilation Error – CE
                    Accepted – AC

                If a problem is Accepted the penalty raises to the amount of minutes it took to accept
                and for each submission before the first Accepted one, the penalty raises by 20 points.
                If the problem is not Accepted, the penalty is zero.

Input:          In the first line of the input a single integer N (1 <= N <= 100) representing the number of
                submissions. The next N lines describe a single submission: with a integer Mi (1 <= Mi <= 300)
                representing the minute of the submission and a string V representing the verdict, both
                values are space separated. The value of V is one of these: WA, TLE, RTE, CE or AC. You can
                safely assume that all Mi are unique.

Output:         The total penalty the team will have after all submissions are processed.

Sample input
4
40 RTE
20 WA
30 WA
41 AC

Sample output
101
 **/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool sortByTime(const pair<int,string> &sub1, const pair<int,string> &sub2){
  return sub1.first < sub2.first;
}

int main(){
  int k;
  cin >> k;
  vector<pair<int,string>> submissions;
  while (k--){
    int time;
    string veredict;
    cin >> time >> veredict;
    submissions.push_back({time, veredict});
  }

  sort(submissions.begin(), submissions.end(), sortByTime);

  size_t penalties = 0;
  bool wasAccepted = false;
  for (auto &tuple : submissions){
    if (tuple.second[0] == 'A'){
      wasAccepted = true;
      penalties += tuple.first;
      break;
    }
    penalties += 20;
  }

  cout << (wasAccepted ? penalties : 0) << endl;
}