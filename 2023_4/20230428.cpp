/*
https://www.acmicpc.net/problem/12865
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N (100)
#define MAX_K (100000)

using namespace std;
int N, K;
int DP[MAX_N + 1][MAX_K + 1]; //[item 0 ~ N - 1][maxWeight 1~K]

void Solve() {
	//init
	for (int i = 0; i <= MAX_N; ++i) {
		for (int j = 0; j <= MAX_K; ++j) {
			DP[i][j] = 0;
		}
	}

	cin >> N >> K;
	int answer = 0;
	for (int i = 1; i <= N; ++i) { // for each item
		int w, v; //weight, value
		cin >> w >> v;
		for (int k = 1; k <= K; ++k) { //for each maximum weight
			//not take current
			int nTake = DP[i - 1][k];

			//take current
			int take = 0;
			if (w <= k) {
				take = DP[i - 1][k - w] + v;
			}
			
			DP[i][k] = max(nTake, take);
			answer = max(answer, DP[i][k]);
		}
	}

	cout << answer << '\n';
}

int main() {
	Solve();
	return 0;
}