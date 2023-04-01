/*
https://www.acmicpc.net/problem/1753
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define INF (INT_MAX - 50)

using namespace std;

int V, E;
int K;
vector<vector<pair<int, int>>> A; // src -> dst, cost

vector<bool> visit;
vector<int> dists;

void Sol();

int main() {
    Sol();
    return 0;
}

void Sol() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> K;

    A.clear();
    A.resize(V + 1);
    visit.resize(V + 1);
    dists.resize(V + 1);

    //pair : dist, nodeNum

    for (int i = 0; i < E; ++i) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        A[src].push_back(make_pair(dst, cost));
    }

    for (int j = 1; j <= V; ++j) {
        dists[j] = j == K ? 0 : INF; //거리 배열 초기화
        visit[j] = false; //방문 배열 초기화
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dists[K], K}); //출발 노드를 우선순위 큐에 넣기
    
    while (!pq.empty()) {
        pair<int, int> dn = pq.top();
        int dist = dn.first;
        int node = dn.second;

        pq.pop();
        if(visit[node] == false) { //이미 방문한 노드라면 버림
            visit[node] = true;
            for(pair<int, int> next : A[node]) {
                int dst = next.first;
                int cost = next.second;

                //값이 갱신된다면 최소 dist를 가지게 될 가능성이 생기므로 pq에 push
                if(visit[dst] == false && dists[node] + cost < dists[dst]) {
                    dists[dst] = dists[node] + cost;
                    pq.push({dists[dst], dst});
                }
            }
        }

        
    }

    for (int n = 1; n <= V; ++n) {
        if (dists[n] == INF) {
            cout << "INF" << '\n';
        }
        else {
            cout << dists[n] << '\n';
        }
    }
}