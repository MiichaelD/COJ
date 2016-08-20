// http://coj.uci.cu/24h/problem.xhtml?pid=1270 Death Knight Hero
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


int main() {
	int n, m;
    cin >> n;
    m = n;
    string str;
    while (n--){
        cin >> str;
        bool wasPreviousC = false;
        for (int i = 0 ; i < str.length(); ++i){
            if (wasPreviousC && str[i] == 'D'){
                --m;
                break;
            }
            wasPreviousC = str[i] == 'C'; 
        }
    }
    cout << m << endl;
}
