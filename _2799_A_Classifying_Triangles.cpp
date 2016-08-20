// http://coj.uci.cu/24h/problem.xhtml?pid=2799 Classifying Triangles
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


int main() {
	vector<int> angles;
	int sixties = 0;
	int anglesSum = 0;
	for (int i = 0; i < 3; ++i) {
		int x;
		cin >> x;
		angles.push_back(x);
		anglesSum += x;
		if (x == 60) 
			++sixties;
	}
	if (anglesSum != 180) {
		cout << "Error" << endl;
	} else if (sixties == 3) {
		cout << "Equilateral" << endl;
	} else {
		sort(angles.begin(), angles.end());
		if (angles[0] == angles[1] || angles[1] == angles[2]) {
			cout << "Isosceles" << endl;
		} else {
			cout << "Scalene" << endl;
		}
	}

	
}
