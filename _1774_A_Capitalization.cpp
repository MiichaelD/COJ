// http://coj.uci.cu/24h/problem.xhtml?pid=1774

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

bool isLowerCase(char c){
	return (c >= 'a' && c <= 'z');
}

bool isUpperCase(char c){
	return (c>='A' && c <= 'Z');
}

char toLowerCase(char c){
	if (isUpperCase(c))
  		return c+('a'-'A');
	return c;
}

char toUpperCase(char c){
	if (isLowerCase(c))
		return c-('a'-'A');
	return c;
}


int main() {
    string str;
    cin >> str;
    
    bool capsLockByAccident = false;
    for (int i = 1 ; i < str.length(); ++i){
    	if (isUpperCase(str[i])){
    		capsLockByAccident = true;
            break;
    	}
    }

    if( capsLockByAccident){
        for (int i = 0 ; i < str.length(); ++i){
            str[i] = isUpperCase(str[i]) ? toLowerCase(str[i]) : toUpperCase(str[i]);
            
        }
    }
    cout << str << endl;
}
