/*
https://www.acmicpc.net/problem/14916
*/
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;
int N;
int DP[100005];

int main() {
	for (int i = 0; i < 100005; ++i) {
		DP[i] = INT_MAX;
	}
	cin >> N;

	//use 2
	DP[0] = 0;
	for (int i = 0; i <= N - 2; ++i) {
		if (DP[i] != INT_MAX) {
			DP[i + 2] = min(DP[i] + 1, DP[i + 2]);
		}
	}

	//use 5
	for (int j = 0; j <= N - 5; ++j) {
		if (DP[j] != INT_MAX) {
			DP[j + 5] = min(DP[j] + 1, DP[j + 5]);
		}
	}

	int answer;
	if (DP[N] == INT_MAX) {
		answer = -1;
	}
	else {
		answer = DP[N];
	}

	cout << answer << '\n';

	return 0;
}