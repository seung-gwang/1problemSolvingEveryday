/*
https://www.acmicpc.net/problem/2212
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;


int main() {
	int N, K;
	cin >> N;
	cin >> K;

	vector<int> A(N);

	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	vector<int> D(N - 1);

	for (int j = 0; j < N - 1; ++j) {
		D[j] = A[j + 1] - A[j];
	}

	sort(D.begin(), D.end());

	int sum = 0;
	for (int m = 0; m < N - K; ++m) {
		sum += D[m];
	}

	cout << sum << endl;

	return 0;
}