/*
https://www.acmicpc.net/problem/1946
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define MAX_N (100000)
using namespace std;

int T;
int N;
typedef pair<int, int> s_m;
s_m P[MAX_N + 1];

inline void Subsolve() {
	cin >> N;
	for (int n = 0; n < N; ++n) {
		int s, m;
		cin >> s >> m;

		P[n].first = s; //서류
		P[n].second = m; //면접
	}
	sort(P, P + N);

	int answer = N;
	int minM = INT_MAX;
	for (int i = 0; i < N; ++i) {
		if (P[i].second > minM) {
			answer--;
		}
		minM = min(minM, P[i].second);
	}
	
	cout << answer << '\n';

}

inline void Solve() {
	cin >> T;
	while (T--) {
		Subsolve();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}
