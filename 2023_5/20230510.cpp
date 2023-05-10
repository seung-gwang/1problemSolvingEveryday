/*
https://www.acmicpc.net/problem/2667
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int MAP[25][25];
void Solve();
void BFS(int y, int x);
vector<int> counts;

int main() {
    Solve();
    return 0;
}

void BFS(int y, int x) {
    int count = 0;
    int dy[] = { -1, 1, 0, 0 };
    int dx[] = { 0, 0, -1, 1 };

    queue<pair<int, int>> q;
    q.push({ y, x });
    MAP[y][x] = 0;
    count++;

    while (!q.empty()) {
        int popCount = q.size();
        while (popCount--) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int ny = cy + dy[d];
                int nx = cx + dx[d];

                if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1) {
                    continue;
                }

                if (MAP[ny][nx] == 1) {
                    MAP[ny][nx] = 0;
                    count++;
                    q.push({ ny, nx });
                }
                
            }
        }
    }
    counts.push_back(count);
}

void Solve() {
    cin >> N;
    counts.clear();

    for (int i = 0; i < N; ++i) {
        string bits;
        cin >> bits;
        for (int j = 0; j < N; ++j) {
            MAP[i][j] = bits[j] - '0';
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (MAP[i][j] == 1) {
                BFS(i, j);
            }
        }
    }

    sort(counts.begin(), counts.end());

    cout << counts.size() << '\n';
    for (const auto& c : counts) {
        cout << c << '\n';
    }
}