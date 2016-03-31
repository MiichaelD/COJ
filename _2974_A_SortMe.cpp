#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/*
8 UVWXYZNOPQRSTHIJKLMABCDEFG
ANTLER
ANY
COW
HILL
HOW
HOWEVER
WHATEVER
ZONE
5 ZYXWVUTSRQPONMLKJIHGFEDCBA
GO
ALL
ACM
TEAMS
GO
10 ZOTFISENWABCDGHJKLMPQRUVXY
THREE
ONE
NINE
FIVE
SEVEN
ZERO
TWO
FOUR
EIGHT
SIX
0
Sample output

year 1
WHATEVER
ZONE
HOW
HOWEVER
HILL
ANY
ANTLER
COW
year 2
TEAMS
GO
GO
ALL
ACM
year 3
ZERO
ONE
TWO
THREE
FOUR
FIVE
SIX
SEVEN
EIGHT
NINE


7 ZYXWVUTSRQPONMLKJIHGFEDCBA
GOOO
ALL
ACM
TEAMS
GOOO
GOO
GO
0


*/
using namespace std;

string sortOrderStr;

bool customOrder(const string &word1, const string &word2){
	int pos1, pos2;
	int len1 = word1.length();
	int len2 = word2.length();
	int index = 0;
	do{
		const char *char1 = &word1[index];
		const char *char2 = &word2[index];
		// cout << "\tcomparing chars: " << char1[0] << " & " << char2[0];
		++index;
		pos1 = sortOrderStr.find(char1, 0, 1);
		pos2 = sortOrderStr.find(char2, 0, 1);
		// cout << ". valus: 1) " <<  pos1 << ", 2) "<< pos2 << endl;
	} while(pos1 == pos2 && index < len1 && index < len2 );
	// cout << "comparing " << word1 << " & " << word2 << ". first: " << (pos1 < pos2 ? word1 : word2) <<
	// 		". different char: " << index << ". index in string: " << (pos1 < pos2 ? pos1 : pos2) << endl;
	
	if (pos1 == pos2){
		return len1 < len2;
	}
	return pos1 < pos2;
}

void printVector(vector<string> &vec){
	for(const string &word : vec){
		cout << word << endl;
	}
}

int main(){
	int cases = 0;
	int wordsAmt;
	do{
		cin >> wordsAmt;
		if (wordsAmt == 0)
			break;
		cin >> sortOrderStr; 
		vector<string> words;
		while (wordsAmt){
			string word;
			cin >> word;
			words.emplace_back(word);
			--wordsAmt;
		}
		std::sort(words.begin(), words.end(), customOrder);
		cout << "year " << ++cases << endl;
		printVector(words);

	}while(true);
	return 0;
}