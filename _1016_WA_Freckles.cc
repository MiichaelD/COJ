/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=1016
 *  Programmer: Michael Duarte
 *  Date:       November 12th 2019
 */

#include <algorithm> // std::sort
#include <iostream>
#include <ctype.h>  // char related functions
#include <cmath>   // pow, floor, sqrt
#include <deque>
#include <limits> // std::numeric_limits<T>::max
#include <memory>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const &pair) const {
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);
		return h1 ^ h2;
	}
};

double calculateDistance(const pair<double, double> &p1, const pair<double, double> &p2) {
  int deltaX = p1.first - p2.first;
  int deltaY = p1.second - p2.second;
  return sqrt((deltaX * deltaX) + (deltaY * deltaY));
}

void printMatrix(const vector<vector<double>> &matrix) {
  cout << "Nodes distances Matrix: " << endl;
  for (int i = 0 ; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

void solve() {
  int nodes;
  double x, y;
  cin >> nodes;
  vector<pair<double, double>> points;
  vector<vector<double>> nodesMatrix(nodes, vector<double>(nodes + 2));
  for (int i = 0 ; i < nodes; ++i) {
    cin >> x >> y;
    points.emplace_back(std::make_pair(x, y));
  }

  double minDistanceSum = 0.0;
  // unordered_set<pair<int,int>, pair_hash> visitedEdges;
  for (int i = 0 ; i < nodes; ++i) {
    double minDistance = std::numeric_limits<double>::max();
    int minDistanceInd = -1;
    for (int j = 0; j < nodes; ++j) {
      if (i == j) {
        nodesMatrix[i][j] = 0;
      } else if (!nodesMatrix[i][j]) {
        nodesMatrix[i][j] = nodesMatrix[j][i] = calculateDistance(points[i], points[j]);
      }
      if (nodesMatrix[i][j] && nodesMatrix[i][j] < minDistance) {
        minDistance = nodesMatrix[i][j];
        minDistanceInd = j;
      }
    }
    nodesMatrix[i][nodes] = minDistance;
    nodesMatrix[i][nodes + 1] = minDistanceInd;

    if (i == 0 || nodesMatrix[minDistanceInd][nodes + 1] != i) {
      minDistanceSum += minDistance;
    }

    // int minInd = i < minDistanceInd ? i : minDistanceInd;
    // int maxInd = i > minDistanceInd ? i : minDistanceInd;
    // pair<int,int> edge = make_pair(minInd, maxInd);
    // if (visitedEdges.find(edge) == visitedEdges.end()) {
    //   visitedEdges.insert(edge);
    //   minDistanceSum += minDistance;
    // }
  }
  // printMatrix(nodesMatrix);
  cout << floor(minDistanceSum * 100) / 100 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return EXIT_SUCCESS;
}
