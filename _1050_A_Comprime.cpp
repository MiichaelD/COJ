#include <iostream>

int gcd(int a, int b) { // find greatest common divisor
    return b == 0 ? a : gcd(b, a % b);
}


int totalComprimeNumbers(int n){
    int count = 0;
    for (int i = n-1; i > 0 ; --i ){
        if (gcd(n, i ) == 1 ){
            ++count;
        }
         // cout << i << " & " << n << ": " <<  gcd(n, i) << endl;
    }
    return count;
}

int totalComprimeNumbers2(int n){ // twice as fast as we only check half of the numbers
    int count = 0;
    for (int i = n/2; i > 0 ; --i ){
        if (gcd(n, i ) == 1 ){
            ++count;
        }
         // cout << i << " & " << n << ": " <<  gcd(n, i) << endl;
    }
    return count * 2;
}


int main(){
    using namespace std;
    int n;
    cin >> n;
    int count = 0;
    cout << totalComprimeNumbers2(n) << endl;
    
    return 0;
}
