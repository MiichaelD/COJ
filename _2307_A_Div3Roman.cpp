#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 *Description:  Roman numerals, the numeric system used in ancient Rome, employs combinations of letters
                from the Latin alphabet to signify values. In the system of Roman numerals, I is the
                symbol for 1, V for 5, X for 10, L for 50, C for 100, D for 500 and M for 1000. Some
                examples of decimal numbers written in the system of roman numerals are:

                Decimal System / Roman Numerals
                2 / II
                4 / IV
                8 / VIII
                9 / IX
                59 / LIX

                You have to determine if a Z (1 <= Z <= 3000) number given in the system of Roman numerals
                is divisible by 3.

Input:          The first line of the input contains an integer N (1 <= N <= 1000) indicating the number
                of test cases. Each of the remaining N lines contains a number in the Roman numerical system.
                You can safelyassume that numbers are correctly writen, acording to Roman numerical system rules.

Output:         For each test case output should contain a line with the word YES if the number is divisible by
                3 or the word NO if not and then the corresponding integer in decimal system.

Sample input
1
IX

Sample output
YES 9

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
        int dec = romanToDecimal(input);
        
        cout << (dec%3==0?"YES ":"NO ") << dec<< endl;
    }
    
}