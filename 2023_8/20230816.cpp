/*
https://www.acmicpc.net/problem/1753
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
#define INF (INT_MAX - 5000)
using namespace std;
void Solve();
typedef pair<int, int> weight_dst;
int V, E, K;
vector<vector<weight_dst>> A; /*Adjacent list*/
vector<bool> visit;
vector<int> dist;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
}

void Solve() {
    cin >> V >> E;
    A.clear();
    visit.resize(V + 1);
    dist.resize(V + 1);
    fill(visit.begin(), visit.end(), false);
    fill(dist.begin(), dist.end(), INF);
    A.resize(V + 1);

    cin >> K; /*시작 정점의 번호*/
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(weight_dst{ w,v });
    }

    /*Dijkstra*/
    priority_queue<weight_dst, vector<weight_dst>, greater<>> pq;
    pq.push({ 0, K });
    dist[K] = 0;
    while (!pq.empty()) {
        weight_dst cur = pq.top();
        pq.pop();
        if (visit[cur.second]) {
            continue;
        }

        visit[cur.second] = true;
        dist[cur.second] = min(dist[cur.second], cur.first);

        for (const auto& next : A[cur.second]) {
            if (!visit[next.second]) {
                pq.push({next.first + dist[cur.second], next.second});
            }
        }

    }

    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << dist[i] << '\n';
        }
    }
}