
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdint>
#include <unordered_map>

using namespace std;

inline int64_t reverse(int64_t num){
	int64_t res = 0, aux;
	int index = floor(log10(num))+1;
	while (num > 0){
		aux = num % 10;
		num /= 10;
		aux *= pow(10, --index);
		res += aux;
	}
	return res;
}

inline void solutionInt(){
	int n;
	int64_t num, reversed;
	unordered_map<int, int> memo;
	cin >> n;
	vector<int64_t> numbers;
	numbers.reserve(n);
	while (n--){
		cin >> num;
		if (memo.find(num) != memo.end()){
			reversed = memo[num];
		} else {
			reversed = reverse(num);
			memo[num] = reversed;
		}

		numbers.push_back(reversed);
		// cout << "\t" << *(numbers.end()-1) << endl;
	}

	sort(numbers.begin(), numbers.end());
	for (int64_t num : numbers){
		cout << num << endl;
	}
}

int main(){
	std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
	cin.tie(NULL);
	solutionInt();
	return 0;
}