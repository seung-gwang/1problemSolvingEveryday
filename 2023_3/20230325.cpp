/*
https://www.acmicpc.net/problem/1197
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct edge {
    int node1;
    int node2;
    int cost;
}edge_t;

bool compare(edge_t e1, edge_t e2) {
    return e1.cost < e2.cost;
}

int V, E; //정점 수, 간선 수
vector<edge_t> edges;
vector<int> parents;

int Find(int node);
void Union(int node1, int node2);

int main() {
    edges.clear();
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back(edge_t{ A, B, C });
    }

    //가중치 기준 정렬
    sort(edges.begin(), edges.end(), compare);

    //유니온파인드 부모배열 생성
    parents.resize(V + 1);
    for (int v = 1; v <= V; ++v) {
        parents[v] = v;
    }

    int spanSum = 0;
    int edgeCount = 0;
    for (edge_t e : edges) {
        int n1 = e.node1;
        int n2 = e.node2;
        int cost = e.cost;

        if (Find(n1) != Find(n2)) {
            spanSum += cost;
            Union(n1, n2);
            edgeCount++;
        }

        if (edgeCount == V - 1) {
            break;
        }
    }

    cout << spanSum << '\n';

    return 0;
}

int Find(int node) {
    if (parents[node] == node) {
        return node;
    }
    int ret = Find(parents[node]);
    parents[node] = ret;
    return ret;
}

void Union(int node1, int node2) {
    int p1 = Find(node1);
    int p2 = Find(node2);
    parents[p2] = p1;
}

