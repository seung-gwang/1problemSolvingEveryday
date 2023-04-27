/*
https://www.acmicpc.net/problem/2720
*/
#include <iostream>
#include <vector>
using namespace std;

const int Q = 25;
const int D = 10;
const int N = 5;
const int P = 1;

int T, C;

void Subsolve() {
	cin >> C;
	int q = C / Q;
	C -= (Q * q);

	int d = C / D;
	C -= (D * d);

	int n = C / N;
	C -= (N * n);

	int p = C;

	cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
}

void Solve() {
	cin >> T;
	while (T--) {
		Subsolve();
	}
}

int main() {
	Solve();
	return 0;
}