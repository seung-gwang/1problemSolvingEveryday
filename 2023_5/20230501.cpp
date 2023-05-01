/*
https://www.acmicpc.net/problem/2812
*/
#include <iostream>
#include <vector>
using namespace std;
int N, K;
string number;

void Solve();
int main() {
	Solve();
	return 0;
}

void Solve() {
	cin >> N >> K;
	cin >> number;

	vector<int> answer;

	int target = N - K;
	int startIdx = 0;
	for (int i = 0; i < target; ++i) {
		char n = '0' - 1;
		for (int j = startIdx; j <= N - (target - i); ++j) {
			if (number[j] > n) {
				n = number[j];
				startIdx = j + 1;
				if (n == '9') { break; }
			}
		}
		answer.push_back(n - '0');
	}

	for (const auto& i : answer) {
		cout << i;
	}
	cout << '\n';
}
