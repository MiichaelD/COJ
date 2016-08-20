// http://coj.uci.cu/24h/problem.xhtml?pid=1428 Packets
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE 6
// #define PRINTLOGS


uint64_t input[MAX_SIZE + 1];
uint64_t totalParcels;

void printRemainingPackets(const string &msg = ""){
#ifdef PRINTLOGS
	cout << msg << "\tTotal Parcels: " << totalParcels << "\t"; 
	for (int i = 1; i <= MAX_SIZE; ++i) 
		cout << input[i] << " "; 
	cout << endl;
#endif
}

uint64_t fillBox(int boxSize, uint64_t available){
	if (available <= input[boxSize]){
		input[boxSize] -= available;
	} else {
		available -= input[boxSize];
		input[boxSize] = 0;
		return available;
	}
	return 0;
}

void process6sAnd5s(){
	totalParcels = input[6];
	if (input[6]){
		input[6] = 0;
		printRemainingPackets("\tprocess6s");
	}

	if (input[5]){
		totalParcels += input[5];
		uint64_t fives = input[5];
		input[5] = 0;
		printRemainingPackets("\tprocess5s - 5");
		fillBox(1, 11 * fives);
		printRemainingPackets("\tprocess5s - 1");
	}
}

void process4s(){
	if (input[4]){
		totalParcels += input[4];
		uint64_t fours = input[4];
		input[4] = 0;
		printRemainingPackets("\tprocess4s - 4");
		uint64_t remaining = fillBox(2, 5 * fours);
		printRemainingPackets("\tprocess4s - 2");
		fillBox(1, 4 * remaining);
		printRemainingPackets("\tprocess4s - 1");
	}
}

void process3s(){
	totalParcels += input[3] / 4;
	uint64_t threes = input[3] % 4;
	input[3] = 0;
	if (threes){
		++totalParcels;
		printRemainingPackets("\tprocess3s - 3");
		uint64_t remaining = fillBox(2, 7 - (2 * threes) );
		printRemainingPackets("\tprocess3s - 2");
		fillBox(1, (4 * remaining) + (8 - threes) );
		printRemainingPackets("\tprocess3s - 1");
	} else 
		printRemainingPackets("\tprocess3s - 3");
}

void process2s(){
	totalParcels += input[2] / 9;
	uint64_t twos = input[2] % 9;
	input[2] = 0;
	if (twos){
		++totalParcels;
		printRemainingPackets("\tprocess2s - 2");
		fillBox(1, 4 * twos);
		printRemainingPackets("\tprocess2s - 1");
	}
}

void process1s(){
	if (input[1]){
		totalParcels += input[1] / 36;
		input[1] %= 36;
		if (input[1]){
			++totalParcels;
			input[1] = 0;
		}
		printRemainingPackets("\tprocess1s - 1");
	}
}

int main() {
	while (true) {
		bool allZeroes = true;
		for (int i = 1; i <= MAX_SIZE; ++i) {
			int x;
			cin >> x;
			input[i] = x;
			if (x != 0)
				allZeroes = false;
		}
		if (allZeroes)
			break;

		process6sAnd5s();
		process4s();
		process3s();
		process2s();
		process1s();
		
		cout << totalParcels << endl;
	}
}
