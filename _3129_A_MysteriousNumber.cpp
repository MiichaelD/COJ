#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int cases;
    cin >> cases;
    cin.ignore();
    while (cases--){
        string line, trick;
        int maxVal, p;
        getline(cin, line);
        
        stringstream ss(line);
        ss >> maxVal >> trick >> p;

        cout << (trick == "even" ? p*2-1 : p*2) << endl;
    }
}