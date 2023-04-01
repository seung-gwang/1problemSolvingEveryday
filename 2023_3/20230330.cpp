/*
https://www.acmicpc.net/problem/4485
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF (9999999)

using namespace std;

typedef struct edge {
    int dst;
    int cost;
} edge_t;

int N;
int R[125][125];
vector<vector<edge_t>> A;
vector<int> MIN_DISTS;
vector<bool> VISIT;
int CASE_NUM;

bool compare(edge_t& left, edge& right) {
    return left.cost < right.cost;
}

void Sol() {
    A.clear();
    A.resize(N  * N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> R[i][j];
        }
    }

    int dy[] = { -1, 1, 0, 0 }; //상하좌우
    int dx[] = { 0, 0, -1, 1 };

    //인접 리스트로 다시 표현
    for (int cy = 0; cy < N; ++cy) {
        for (int cx = 0; cx < N; ++cx) {
            int src = cy * N + cx;

            for (int dir = 0; dir < 4; ++dir) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];

                if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1) { continue; }

                int dst = ny * N + nx;
                A[src].push_back({ dst, R[ny][nx] });
            }
        }
    }

    MIN_DISTS.clear();
    MIN_DISTS.resize(N * N);
    fill(MIN_DISTS.begin(), MIN_DISTS.end(), INF);
    VISIT.clear();
    VISIT.resize(N * N);
    fill(VISIT.begin(), VISIT.end(), false);

    MIN_DISTS[0] = 0; // 출발노드 비용 0

    //다익스트라
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //pair : cost-node
    pq.push({ R[0][0],0});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (VISIT[cur] == true) { continue; }
        VISIT[cur] = true;

        for (edge_t edgeToNext : A[cur]) {
            int next = edgeToNext.dst;

            if (MIN_DISTS[next] > cost + edgeToNext.cost) {
                MIN_DISTS[next] = cost + edgeToNext.cost;
                pq.push({ MIN_DISTS[next], next });
            }
        }
    }

    cout << "Problem " << CASE_NUM << ": " <<  MIN_DISTS[N * N - 1] << '\n';
}

int main() {
    CASE_NUM = 1;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        Sol();
        CASE_NUM++;
    }

}

