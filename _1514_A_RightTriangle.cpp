// http://coj.uci.cu/24h/problem.xhtml?pid=1514 Right TRiangle
//

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


int main() {
    double A, B, C, area ;
    int n;
    cin >> n;
    while (n--){
        cin >> A >> B;
        area = A * B / 2; //triangles area;
        C = area / ((A + B)/ 2); // square side length
        area = C * C;
        printf("%.5lg\n",area);   
    }
}
