/*
https://www.acmicpc.net/problem/10653
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

int N;
int K;
int dist[501][501];
int DP[501][501];
vector<pair<int, int>> node_coords;

void Solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}

int getDist(const int src, const int dst) {
    return abs(node_coords[src].first - node_coords[dst].first) + abs(node_coords[src].second - node_coords[dst].second);
}

void Solve() {
    for (int i = 0; i < 501; ++i) {
        for (int j = 0; j < 501; ++j) {
            dist[i][j] = INT_MAX;
            DP[i][j] = INT_MAX;
        }
    }
    cin >> N >> K;
    node_coords.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        int x, y;
        cin >> x >> y;
        node_coords[i] = { x, y };
    }

    for (int dst = 1; dst <= N; ++dst) {
        for (int src = 1; src < dst; ++src) {
            dist[src][dst] = getDist(src, dst);
        }
    }

    if (N - 2 - K == 0) {
        cout << dist[1][N] << '\n';
        return;
    }


    for (int t = 2; t <= N - 1; ++t) {
        DP[1][t] = dist[1][t] + dist[t][N];
    }

    for (int i = 1; i < N - 2 - K; ++i) {
        for (int j = 2; j <= N - 1; ++j) {
            if (DP[i][j] != INT_MAX) {
                for (int k = j + 1; k < N; ++k) {
                    DP[i + 1][k] = min(DP[i + 1][k], DP[i][j] + dist[j][k] + dist[k][N] - dist[j][N]);
                }

            }
        }
    }

    int answer = INT_MAX;
    for (int skipCount = 0; skipCount <= K; ++skipCount) {
        for (int v = 2; v <= N - 1; ++v) {
            answer = min(answer, DP[N - 2 - skipCount][v]);
        }
    }

    cout << answer << '\n';
}