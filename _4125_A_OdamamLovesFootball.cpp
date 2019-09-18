#include <string>
#include <iostream>


int main(){
	std::string input;

	std::cin >> input;
	int continuousSameTeamPlayers = 0;
	char currentTeam = '_';
	for (int k = 0 ; k < input.length(); ++k) {
		if (input.at(k) != currentTeam) {
			currentTeam = input.at(k);
			continuousSameTeamPlayers = 1;
		} else if (++continuousSameTeamPlayers >= 7) {
			break;
		}
	}
	std::cout << (continuousSameTeamPlayers >= 7 ? "YES" : "NO") << std::endl;
}
