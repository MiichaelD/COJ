//http://coj.uci.cu/24h/problem.xhtml?pid=4166

#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <utility>

using namespace std;

int MAX_VALUE = 1000000;

template<typename _Ty1, typename _Ty2>
std::ostream& operator<<(std::ostream& dest, const std::pair<_Ty1, _Ty2>& pair) {
  dest << "[" << (pair.first) << ", " << (pair.second) << "]";
  return dest;
}

int getDistance(const pair<int,int> &coordinate1, const pair<int,int> &coordinate2) {
  int deltaX = abs(coordinate1.first - coordinate2.first);
  int deltaY = abs(coordinate1.second - coordinate2.second);
  int delta = deltaX + deltaY;
  return delta;
}

int findMaxDistance1(const vector<pair<int,int>> &coordinates) {
  int maxDistance = 0;
  for (int i = 0; i < coordinates.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      int delta = getDistance(coordinates[i], coordinates[j]);
      if (delta > maxDistance) {
        cout << "Max diff: " << coordinates[i] << " and " << coordinates[j] << endl;
        maxDistance = delta;
      }
    }
  }
  return maxDistance;
}

int findMaxDistance2(const vector<pair<int,int>> &coordinates) {
  int maxDistance = 0;
  int topPairInd = 0, leftPairInd = 0, rightPairInd = 0, bottomPairInd = 0;
  for (int i = 1; i < coordinates.size(); ++i) {
    if (coordinates[i].first < coordinates[leftPairInd].first) {
      leftPairInd = i;
    } else  if (coordinates[i].first > coordinates[rightPairInd].first) {
      rightPairInd = i;
    }
    if (coordinates[i].second < coordinates[topPairInd].second) {
      topPairInd = i;
    } else  if (coordinates[i].second > coordinates[bottomPairInd].second) {
      bottomPairInd = i;
    }
  }

  vector<int> edges;
  edges.push_back(topPairInd);
  edges.push_back(leftPairInd);
  edges.push_back(rightPairInd);
  edges.push_back(bottomPairInd);
  for (int h = 0; h < edges.size(); ++h) {
    for (int i = 0; i < edges.size(); ++i) {
      if (i == h) continue;      
      int delta = getDistance(coordinates[edges[h]], coordinates[edges[i]]);
      if (delta > maxDistance) {
        maxDistance = delta;
      }
    }
  }
  // int verDis = getDistance(coordinates[topPairInd], coordinates[bottomPairInd]);
  // int horDis = getDistance(coordinates[leftPairInd], coordinates[rightPairInd]);
  // int topRightDis = getDistance(coordinates[topPairInd], coordinates[rightPairInd]);
  // int topLeftDis = getDistance(coordinates[topPairInd], coordinates[leftPairInd]);
  // int bottomRightDis = getDistance(coordinates[bottomPairInd], coordinates[rightPairInd]);
  // int bottomLeftDis = getDistance(coordinates[bottomPairInd], coordinates[leftPairInd]);
  // return max(max(max(max(max(verDis, horDis), topRightDis), topLeftDis), bottomRightDis),
  //  bottomLeftDis);
  return maxDistance;
}

int findMaxDistance3(const vector<pair<int,int>> &coordinates) {
  int maxDistance = 0;
  int topPairInd = 0, leftPairInd = 0, rightPairInd = 0, bottomPairInd = 0;
  for (int i = 1; i < coordinates.size(); ++i) {
    if (coordinates[i].first < coordinates[leftPairInd].first) {
      leftPairInd = i;
    } else  if (coordinates[i].first > coordinates[rightPairInd].first) {
      rightPairInd = i;
    }
    if (coordinates[i].second < coordinates[topPairInd].second) {
      topPairInd = i;
    } else  if (coordinates[i].second > coordinates[bottomPairInd].second) {
      bottomPairInd = i;
    }
  }
  vector<int> edges;
  edges.push_back(topPairInd);
  edges.push_back(leftPairInd);
  edges.push_back(rightPairInd);
  edges.push_back(bottomPairInd);

  for (int h = 0; h < edges.size(); ++h) {
    for (int i = 0; i < coordinates.size(); ++i) {
      if (i == h) continue;
      int delta = getDistance(coordinates[edges[h]], coordinates[i]);
      if (delta > maxDistance) {
        maxDistance = delta;
      }
    }
  }
  return maxDistance;
}


int main(){
  std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
  cin.tie(NULL);

  int N, buildings, xi, yi;
  vector<pair<int,int>> coordinates;
  cin >> N;
  while(N--){
    cin >> buildings;
    for (int i = 0; i < buildings; ++i) {
      cin >> xi >> yi;
      coordinates.emplace_back(make_pair(xi, yi));
    }
    cout << findMaxDistance3(coordinates) << endl;
    coordinates.clear();
  }
  return EXIT_SUCCESS;
}
