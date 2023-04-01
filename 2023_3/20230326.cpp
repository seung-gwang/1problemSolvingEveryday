/*
https://www.acmicpc.net/problem/10775
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int G;
int P;

int FindRightmostGate(int n);
vector<int> possibleRightmostGates;

void Sol() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> G;
	cin >> P;

	possibleRightmostGates.resize((G + 1));
	for (int i = 0; i <= G; ++i) {
		possibleRightmostGates[i] = i;
	}


	int answer = 0;
	for (int i = 0; i < P; ++i) {
		int g;
		cin >> g;


		int pos = FindRightmostGate(g);

		if (pos == 0) {
			break;
		}
		else {
			answer++;
		}
	}

	cout << answer << '\n';
}

int FindRightmostGate(int n) {

	if (possibleRightmostGates[n] == n) {
		possibleRightmostGates[n]--;
		return n;
	}

	if (n == 1) {
		return 0;
	}

	int ret = FindRightmostGate(possibleRightmostGates[n]);
	possibleRightmostGates[n] = ret - 1;
	return ret;
}

int main() {
	Sol();
	return 0;
}