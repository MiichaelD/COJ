// http://coj.uci.cu/24h/problem.xhtml?pid=2362

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


int main() {
    int n, i, j;
    cin >> n;
    while (n--){
        cin >> i;
        j = i - 1;
        cout << i*i + j*j << endl;
    }
}
