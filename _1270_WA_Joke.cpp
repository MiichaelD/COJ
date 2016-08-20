// http://coj.uci.cu/24h/problem.xhtml?pid=1270 Joke
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
// typedef unsigned int uint128_t __attribute__((mode(TI)));

std::ostream& operator<<( std::ostream& dest, __int128_t value ){
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

__int128  strToUint128t(const string &in){
	__int128  ret = 0;
	int index = 0;
	for (int i = in.length() - 1; i >= 0; --i, ++index){
		char c = in[i];
		if (c == '.'){
			--index;
		} else {
			ret += (c-'0') * pow(10.0, index);
		}
	}
	// cout << "\t" << ret << endl; 
	return ret;
}

void printSolution(__int128  solution){
	cout << solution << endl;

}

int main() {
	__int128  solution, intx, inty;
	string x, y;
	cin >> x >> y;
	intx = strToUint128t(x);
	inty = strToUint128t(y);
	solution = inty == 0 ? 0 : intx / inty;
	printSolution(solution);
}
