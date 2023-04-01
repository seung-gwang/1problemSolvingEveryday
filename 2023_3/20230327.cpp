/*
https://www.acmicpc.net/problem/17472
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF (9999)
using namespace std;

typedef struct bridge {
	int islandA;
	int islandB;
	int dist;
}bridge_t;

int board[10][10];
int map[10][10];
int N, M;
vector<vector<pair<int, int>>> islands;
vector<bridge_t> bridges;
vector<int> parents;


void BFS(int r, int c, int islandNum); //연결된 땅들을 bfs로 찾고 map에 섬 번호를 표시함
int getMinDist(vector<pair<int, int>>& islandA, vector<pair<int, int>>& islandB);
int Find(int n);
void Union(int a, int b);


bool compare(bridge_t& left, bridge_t& right) {
	return left.dist < right.dist;
}

void Sol() {
	cin >> N >> M;
	islands.clear();
	bridges.clear();
	parents.clear();

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> board[r][c];
			map[r][c] = 0;
		}
	}

	int islandNum = 1;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (board[r][c] == 1 && map[r][c] == 0) {
				BFS(r, c, islandNum);
				islandNum++;
			}
		}
	}

	const int islandCount = islandNum - 1;

	parents.resize(islandNum + 1);
	for (int n = 1; n <= islandNum; ++n) {
		parents[n] = n;
	}

	for (int i = 0; i < islands.size() - 1; ++i) {
		for (int j = i + 1; j < islands.size(); ++j) {
			int islandA = i + 1;
			int islandB = j + 1;
			int minDist = getMinDist(islands[i], islands[j]);

			if (minDist != INF) {
				bridges.push_back({ islandA, islandB, minDist });
			}
		}
	}

	sort(bridges.begin(), bridges.end(), compare);

	int connectCount = 0;
	int bridgeLenSum = 0;
	while (!bridges.empty()) {
		int islandA = bridges.front().islandA;
		int islandB = bridges.front().islandB;
		int bridgeLen = bridges.front().dist;

		bridges.erase(bridges.begin());

		if (bridgeLen == 1) {
			continue;
		}

		if (Find(islandA) != Find(islandB)) {
			Union(islandA, islandB);
			connectCount++;
			bridgeLenSum += bridgeLen;
		}

		if (connectCount == islandCount - 1) {
			break;
		}
	}

	if (connectCount != islandCount - 1) {
		cout << "-1\n";
	}
	else {
		cout << bridgeLenSum << '\n';
	}


}

void BFS(int y, int x, int islandNum) {
	vector<pair<int, int>> island;
	int dx[] = { 0, 0, -1, 1 }; //상하좌우
	int dy[] = { -1, 1, 0, 0 };

	queue<pair<int, int>> q;

	map[y][x] = islandNum;
	island.push_back({ y, x });
	q.push({ y,x });

	while (!q.empty()) {
		int popCount = q.size();

		for (int p = 0; p < popCount; ++p) {
			pair<int, int> coord = q.front();
			q.pop();

			int cy = coord.first;
			int cx = coord.second;

			for (int dir = 0; dir < 4; ++dir) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];

				if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1 || board[ny][nx] == 0 || map[ny][nx] != 0) {
					continue;
				}

				map[ny][nx] = islandNum;
				island.push_back({ ny, nx });
				q.push({ ny, nx });
			}
		}
	}
	islands.push_back(island);
}

int getMinDist(vector<pair<int, int>>& islandA, vector<pair<int, int>>& islandB) {
	int minDist = INF;

	for (pair<int, int> a : islandA) {
		for (pair<int, int> b : islandB) {
			int ay = a.first;
			int ax = a.second;
			int by = b.first;
			int bx = b.second;

			if (ay == by) {
				int start = min(ax, bx);
				int end = max(ax, bx);

				int y = ay;
				bool isOnlyWaterBetween = true;
				for (int x = start + 1; x <= end - 1; ++x) {
					if (board[y][x] != 0) {
						isOnlyWaterBetween = false;
						break;
					}
				}

				if (isOnlyWaterBetween) {
					int len = abs(ax - bx) - 1;
					if (len > 1) {
						minDist = min(minDist, len);
					}
				}
			}

			if (ax == bx) {
				int start = min(ay, by);
				int end = max(ay, by);
				int x = ax;
				bool isOnlyWaterBetween = true;

				for (int y = start + 1; y <= end - 1; ++y) {
					if (board[y][x] != 0) {
						isOnlyWaterBetween = false;
						break;
					}
				}

				if (isOnlyWaterBetween) {
					int len = abs(ay - by) - 1;
					if (len > 1) {
						minDist = min(minDist, len);
					}
				}

			}
		}
	}

	return minDist;
}

int Find(int n) {
	if (parents[n] == n) {
		return n;
	}

	int ret = Find(parents[n]);
	parents[n] = ret;

	return ret;
}
void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	parents[pa] = pb;
}

int main() {
	Sol();
	return 0;
}