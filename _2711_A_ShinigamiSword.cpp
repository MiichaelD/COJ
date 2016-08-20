//http://coj.uci.cu/24h/problem.xhtml?pid=2711

#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <utility>

using namespace std;

bool sortShinigamis(const pair<int,int> &p1, const pair<int,int> &p2){
	return p1.second > p2.second;
}

int main(){
	cin.tie(NULL);
	std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
	int N, aux;
	vector<pair<int,int>> shiniPower;
	cin >> N;
	for (int i = 1 ; i <= N; ++i){
		cin >> aux;
		shiniPower.push_back(make_pair(i, aux));
	}

	sort(shiniPower.begin(), shiniPower.end(), sortShinigamis);

	for(auto &pair : shiniPower){
		cout << pair.first << endl;
	}
}
