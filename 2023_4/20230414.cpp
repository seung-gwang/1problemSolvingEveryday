/*
https://www.acmicpc.net/problem/13549
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define MAX_POS (100000)

using namespace std;
typedef pair<int, int> cost_pos;
int N, K;
bool visit[MAX_POS + 1];
int dists[MAX_POS + 1];
int answer;
int UPPER_LIMIT;

void Solve() {
	cin >> N >> K;
	for (int i = 0; i <= MAX_POS; ++i) {
		visit[i] = false;
		dists[i] = INT_MAX;
	}

	UPPER_LIMIT = MAX_POS;

	priority_queue<cost_pos, vector<cost_pos>, greater<>> pq;
	dists[N] = 0;
	pq.push({ 0, N }); //start from position N with cost 0
	while (!pq.empty()) {
		cost_pos cur = pq.top();
		pq.pop();

		int curPos = cur.second;
		int curCost = cur.first;

		if (visit[curPos] == true) { continue; }
		visit[curPos] = true;


		if (0 <= curPos - 1 && curPos - 1 <= UPPER_LIMIT) {
			pq.push({ curCost + 1, curPos - 1 });
			dists[curPos - 1] = min(dists[curPos - 1], curCost + 1);
		}
		
		if (0 <= curPos + 1 && curPos + 1 <= UPPER_LIMIT) {
			pq.push({ curCost + 1, curPos + 1 });
			dists[curPos + 1] = min(dists[curPos + 1], curCost + 1);
		}
		
		if (2 * curPos <= UPPER_LIMIT) {
			pq.push({ curCost, 2 * curPos });
			dists[2 * curPos] = min(dists[2 * curPos], curCost);
		}
	}

	cout << dists[K] << '\n';

}

int main() {
	Solve();
	return 0;
};