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

// A function to print all prime factors of a given number n
void primeFactors(int n){
    // Print the number of 2s that divide n
    while (n%2 == 0){
        printf("%d ", 2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2){
        // While i divides n, print i and divide n
        while (n%i == 0){
            printf("%d ", i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number greater than 2
    if (n > 2)
        printf ("%d ", n);
}


int findMaxPrimeFactor(int n){
    int maxFactor = 0;
    while (n%2 == 0){
        n = n/2;
        maxFactor = 2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    int sqrtn = static_cast<int>(sqrt(n));
    for (int i = 3; i <= sqrtn; i = i+2){
        // While i divides n, print i and divide n
        while (n%i == 0){
            n = n/i;
            maxFactor = i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number greater than 2
    if (n > 2){
        maxFactor = n;
    }
    return maxFactor;
}


int main(){
    std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
    cin.tie(NULL);

   int N, num;
   cin >> N; cin.ignore();
   int maxFactor = -1, numberWithMaxFactor = -1;
   for (;N--;){
        cin >> num; cin.ignore();
        // cout << num << ": "; 
        // primeFactors(num);
        // cout << endl;
        int greaterFactor = findMaxPrimeFactor(num);
        if (greaterFactor > maxFactor){
            maxFactor = greaterFactor;
            numberWithMaxFactor = num;
        }
   }
   cout << numberWithMaxFactor << endl;
    return 0;
}