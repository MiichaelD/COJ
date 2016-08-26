
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdint>
#include <iomanip>

using namespace std;

const double PI = 3.141592653589793;

double degreeToRadian(double degree){
	return degree * PI / 180.0;
}

double crossArea(double a){
	double a3 = a / 3; // a 3rd of 'a'
	double a3_a3 = a3 * a3;
	double a6 = a3 / 2; // a 6th of 'a'
	double a2 = a / 2; // half 'a'

	double triangleAEL = a3_a3 / 2;
	double lineLE = sqrt(a3_a3 + a3_a3);
	// cout << "\tLineLE = " << lineLE << endl;
	double lineCenterL = sqrt(a6*a6 + a2*a2);
	double lineCenterLEtoCenter = (lineLE / 2) / tan(degreeToRadian(22.5));
	double lineCenterLEtoCenter2 = sqrt((lineCenterL*lineCenterL) - (lineLE/2)*(lineLE/2));
	cout << "\tcateto adyacente: " << lineCenterLEtoCenter << " = " << lineCenterLEtoCenter2  << endl; 
	double triangleCenterEL = sqrt(lineLE*lineLE + lineCenterLEtoCenter2*lineCenterLEtoCenter2);
	double cross = 4 * (triangleAEL + triangleCenterEL);
	cross -= PI * a3_a3;
	return cross;
}

double crossArea2(double a){
	double a3 = a / 3; // a 3rd of 'a'
	double a3_a3 = a3 * a3;

	double area = a * a;
	double circle = PI * a3_a3;
	double triangles = a3 * a;

	return area - circle - triangles;
}

int main(){
	std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
	cin.tie(NULL);

	cout << "PI = " << PI << endl;
	cout << std::fixed;
	while (cin && !cin.eof()){
		double a;
		cin >> a;
		a = crossArea2(a);
		cout << std::setprecision(4) << a << endl;	
	}

	return 0;
}