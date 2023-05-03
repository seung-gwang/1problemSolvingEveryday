/*
https://www.acmicpc.net/problem/15963
*/
#include <iostream>
using namespace std;
typedef long long sll;
sll N, M;

int main() {
	cin >> N >> M;
	int answer = 0;
	if (N == M) {
		answer = 1;
	}

	cout << answer << '\n';
	return 0;
}