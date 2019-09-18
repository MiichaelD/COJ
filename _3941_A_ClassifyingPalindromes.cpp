#include <string>
#include <iostream>

bool isPalindrome(const std::string &str, int start, int end) {
	for(int i = start, j = end - 1; i < j; i++, j--){
		// In case there were spaces -- although there arent in this problem.
		while(str[i] == ' '){  
				i++;
		}
		while(str[j] == ' '){
				j--;
		}
		if(str[i] != str[j]){
			std::cout << "" ;
			return false;
		}    
	}
	return true;
}

std::string classifyPalindrome(const std::string &input) {
	size_t inputLength = input.length();
	if (isPalindrome(input, 0 , inputLength)) {
		return "palindrome";
	}
	for (int i = 1; i < inputLength; ++i) {
		if (isPalindrome(input, 0 , i) && isPalindrome(input, i, inputLength)) {
			return "bi-palindrome";
		}
	}
	return "non-palindrome";
}

int main(){
	int cases;
	std::string input;

	std::cin >> cases;
	for (int k = 0 ; k < cases; ++k) {
		std::cin >> input;
		std::cout << classifyPalindrome(input) << std::endl;
	}
	return EXIT_SUCCESS;
}
