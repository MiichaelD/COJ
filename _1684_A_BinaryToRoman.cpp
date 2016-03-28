#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 *Description:  Lucky is a hacker who is trying to enter in a server system. He realizes that servers
                do not work with binary numbers, instead of that, the server use an model never seen
                that works with roman numbers. All programs created by Lucky are binary, it asks you to
                help make a program that given a number N of binary numbers make it into roman numerals.

Input:          In the first line an integer N represents the number of test cases. Then follow N lines,
                each of which contains a binary number. The number making up the binary will be in a range
                between 1 and 111110100000. [1 - 4000]

Output:         The output consists of N lines, each line will be a roman numeral whose binary equivalent
                is the number given.

Sample input

3
10
1110
1111111

Sample output
II
XIV
CXXVII

 **/
 
unordered_map<char, int> ROMAN_MAP = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int MAX_CONSTANTS = 7;
string ROMAN_CONSTANTS[] = {"I", "V", "X", "L", "C", "D", "M"};
char ROMAN_CONSTANTS2[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int ROMAN_MULTIPLIERS[] = {1, 5, 10, 50, 100, 500, 1000};

int charToInt(const char *str, int &i, size_t length){
	char c = str[i];
	unsigned int negSum = 0;
	if (i < length-1){
		char nextChar = str[i+1];
		if (c == 'I' && (nextChar == 'V' || nextChar == 'X') ){
			negSum = 1;
		} else if (c == 'X' && (nextChar == 'L' || nextChar == 'C')){
			negSum = 10;
		} else if (c == 'C' && (nextChar == 'D' || nextChar == 'M')){
			negSum = 100;
		} 

		if(negSum > 0 ){ 
			++i;
			c = nextChar;
		}
	}
	auto tuple = ROMAN_MAP.find (c);
    int val = tuple == ROMAN_MAP.end() ? 0 : tuple->second;
    return val - negSum;
} 
 
 
int romanToDecimal(const string roman){
    const char *str = roman.c_str();
    size_t length = roman.length();
    int accum = 0;
    for(int i = 0; i < length; ++i){
        accum += charToInt(str, i, length);
    }
    return accum;
}

string decimalToRoman(int dec){
    string roman;
    int i = MAX_CONSTANTS - 1;
    for (;i>=0 && dec > 0 ; --i){
        size_t division = dec / ROMAN_MULTIPLIERS[i];
        if (division > 0){
        	if ( dec == 4){
            	roman.append("IV");
            	dec -= 4;
        	} else if (dec == 9){
				roman.append("IX");	
				dec -= 9;
        	} else if (dec > 39  && dec < 50){
				roman.append("XL");	
        		dec -= 40;
        	}else if (dec > 89 && dec < 100){
				roman.append("XC");	
        		dec -= 90;
        	} else if (dec > 399 && dec< 500){
        		roman.append("CD");
        		dec -= 400;
        	} else if (dec > 899 && dec < 1000){
        		roman.append("CM");
        		dec -= 900;
        	} else{
        		dec %= ROMAN_MULTIPLIERS[i];
            	roman.append(division, ROMAN_CONSTANTS2[i]);
        	}
        }
    }
    return roman;
}

int binaryToDecimal(const string &binary){

    int val = 0;
    int i = binary.length()-1;
    int power = 1;

    for(; i >= 0; --i, power*=2 ){
        if (binary[i] == '1'){
            val+=power;
        }
    }

    return val;
} 

int main()
{
    int cases = 0;
    string input;
    cin >> cases;
    while (cases--){
        cin >> input;
        int dec = binaryToDecimal(input);
        string roman = decimalToRoman(dec);
        cout << roman << endl;
    }
    
}