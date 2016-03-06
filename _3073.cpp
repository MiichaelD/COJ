#include <cstdio>
#include <string>
#include <iostream>

int main(){
	int k;
	scanf("%d",&k);
	while(k--){
		using namespace std;
		string str;
		cin >> str;
		int length = str.length();
		if (length > 10){
			printf("%c%d%c\n",str.at(0),length-2,str.at(length-1));
		} else {
			printf("%s\n",str.c_str());
		}
	}
}
