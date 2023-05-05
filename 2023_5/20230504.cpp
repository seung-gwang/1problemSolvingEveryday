/*
https://www.acmicpc.net/problem/1484
*/
#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;

void Solve();

int main() {
	Solve();
	return 0;
}

void Solve() {
	ull G;
	cin >> G;

	ull rem = 1; //기억하는 몸무게
	ull cur = 1; //현재 몸무게

	vector<ull> answers;
	while (true) {
		ull sqDiff = cur * cur - rem * rem;

		if (sqDiff > 100000 && cur == (rem+1)) {
			break;
		}

		if (sqDiff == G) {
			answers.push_back(cur);
			cur++;
			rem++;
		}
		else if (sqDiff > G) {
			rem++;
		}
		else { //sqDiff < G
			cur++;
		}
	}

	if (answers.size() == 0) {
		cout << "-1" << '\n';
		return;
	}

	for(const auto& a : answers) {
		cout << a << '\n';
	}
}
