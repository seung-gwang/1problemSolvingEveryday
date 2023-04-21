/*
https://www.acmicpc.net/problem/9625
*/
#include <iostream>
#include <vector>
using namespace std;
int K;
int A[46];
int B[46];


void Solve() {
	cin >> K;

	//initially 1 A, 0 B
	A[0] = 1;
	B[0] = 0;

	for (int i = 1; i <= K; ++i) {
		B[i] = A[i - 1] + B[i - 1]; //Previous A change into B, Previous B change into BA
		A[i] = B[i - 1];
	}

	cout << A[K] << ' ' << B[K] << '\n';
}
int main() {
	Solve();
	return 0;
}