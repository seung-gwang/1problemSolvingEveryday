/*
https://www.acmicpc.net/problem/1149
*/
#include <iostream>
#include <vector>
using namespace std;

int DP[3][1001]; //[끝이 R, G, B인 경우][집 번호 ; 1 ~ N]
int N;
typedef struct rgbc{
	int R;
	int G;
	int B;
}rgb_cost;

vector<rgb_cost> costs;

void Solve() {
	costs.clear();
	cin >> N;
	costs.resize(N + 1);


	for (int i = 1; i <= N; ++i) {
		int r, g, b;
		cin >> r >> g >> b;
		costs[i] = rgb_cost{ r, g, b };
	}

	DP[0][1] = costs[1].R;
	DP[1][1] = costs[1].G;
	DP[2][1] = costs[1].B;

	for (int i = 2; i <= N; ++i) {
		DP[0][i] = min(DP[1][i - 1], DP[2][i - 1]) + costs[i].R; //직전 집의 색상과 다른 색으로 칠함
		DP[1][i] = min(DP[0][i - 1], DP[2][i - 1]) + costs[i].G;
		DP[2][i] = min(DP[0][i - 1], DP[1][i - 1]) + costs[i].B;
	}

	int answer = DP[0][N];
	answer = min(answer, DP[1][N]);
	answer = min(answer, DP[2][N]);

	cout << answer << '\n';

}

int main() {
	Solve();
	return 0;
}
