/*
https://www.acmicpc.net/problem/1956
*/
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#define INF (INT_MAX);
typedef unsigned long long ull;
using namespace std;

int V, E;

ull A[401][401];

void Solve();
int main() {
	for (int i = 1; i <= 400; ++i) {
		for (int j = 1; j <= 400; ++j) {
			A[i][j] = INT_MAX;
		}
	}

	Solve();
	return 0;
}

void Solve() {
	cin >> V >> E;
	for (int e = 0; e < E; ++e) {
		int a, b;
		ull w;
		cin >> a >> b >> w;
		A[a][b] = w;
	}

	for (int k = 1; k <= V; ++k) {
		for (int i = 1; i <= V; ++i) {
			for (int j = 1; j <= V; ++j) {
				if (i == j) {
					A[i][j] = 0;
				}
				else if ((A[i][k] != INT_MAX) && (A[k][j] != INT_MAX)){
					A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
				}
			}
		}
	}

	ull answer = ULLONG_MAX;
	bool found = false;
	for (int src = 1; src <= V; ++src) {
		for (int dst = 1; dst <= V; ++dst) {
			if (src == dst) { continue; }
			if (A[src][dst] != INT_MAX && A[dst][src] != INT_MAX) {
				ull temp = A[src][dst] + A[dst][src];
				answer = min(temp, answer);
				found = true;
			}
		}
	}

	if (!found) {
		cout << -1 << '\n';
	}
	else {
		cout << answer << '\n';
	}

	
}