/*
https://www.acmicpc.net/problem/2864
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string numStrA, numStrB;

void Solve();

int main() {
	Solve();
	return 0;
}

void Solve() {
	cin >> numStrA >> numStrB;

	for (int i = 0; i < numStrA.length(); ++i) {
		if (numStrA[i] == '6') {
			numStrA[i] = '5';
		}
	}

	for (int i = 0; i < numStrB.length(); ++i) {
		if (numStrB[i] == '6') {
			numStrB[i] = '5';
		}
	}

	int minVal = stoi(numStrA) + stoi(numStrB);

	for (int i = 0; i < numStrA.length(); ++i) {
		if (numStrA[i] == '5') {
			numStrA[i] = '6';
		}
	}

	for (int i = 0; i < numStrB.length(); ++i) {
		if (numStrB[i] == '5') {
			numStrB[i] = '6';
		}
	}

	int maxVal = stoi(numStrA) + stoi(numStrB);

	cout << minVal << ' ' << maxVal << '\n';
}

