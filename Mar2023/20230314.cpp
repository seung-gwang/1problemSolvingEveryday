/*
https://www.acmicpc.net/problem/14501
*/
#include <iostream>
#include <algorithm>
using namespace std;

int sol();

int main() {
	sol();
	return 0;
}

int sol() {
	const int MAX_N = 15;
	int T[MAX_N + 1] = {0,};
	int P[MAX_N + 1] = {0,};
	int dp[MAX_N + 1] = {0,};

	int N;
	cin >> N;
	
	int answer = 0;

	for (int day = 1; day <= N; ++day) {
		int t, p;
		cin >> t >> p;
		T[day] = t;
		P[day] = p;

		int finDay = day + t - 1;
		 
		for (int before = 0; before < day; ++before) {
			//오늘의 상담이 퇴사일 전에 끝나고, 오늘 이전에 있었던 상담이 오늘 전에 끝남
			int finBefore = before + T[before] - 1;
			if (finDay < N + 1 && finBefore < day) {
				//최대값 갱신
				dp[day] = max(dp[day], dp[before] + P[day]);
				answer = max(answer, dp[day]);
			}
		}
	}

	cout << answer << endl;
	return 0;
}

