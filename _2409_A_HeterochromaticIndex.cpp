// http://coj.uci.cu/24h/problem.xhtml?pid=2409

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


int main() {
    string name;
    int a, b;
    cin >> name >> a >> b;
    cout << name << ' ' << abs(a - b) << endl;
}
