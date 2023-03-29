/*
https://www.acmicpc.net/problem/1414
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define INF (99999)
using namespace std;

typedef struct edge {
    int src;
    int dst;
    int cost;
}edge_t;

int N;
int LAN[51][51];

int LAN_SUM;
vector<edge_t> edges;
vector<int> parents;
/*
행렬 입력 -> 전체 랜선길이 총합 : SUM
MST -> 모든 컴퓨터 연결에 필요한 최소 랜선 길ㅇ : lenMST;
SUM - lenMST
*/

bool compare (edge& left, edge& right) {
    return left.cost < right.cost;
}

int Find(int n);
void Union(int a, int b);

int main() {
    cin >> N;
    LAN_SUM = 0;
    edges.clear();
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            char input;
            cin >> input;

            if('a' <= input && input <= 'z') {
                LAN[i][j] = input - 'a' + 1;
                LAN_SUM += LAN[i][j];
                edges.push_back(edge_t{i, j, LAN[i][j]});
            }
            else if ('A' <= input && input <= 'Z') {
                LAN[i][j] = input - 'A' + 27;
                LAN_SUM += LAN[i][j];
                edges.push_back(edge_t{i, j, LAN[i][j]});
            }
            else {
                LAN[i][j] = INF;
            }
        }
    }

    //Union-Find, MST
    sort(edges.begin(), edges.end(), compare);
    parents.clear();
    parents.resize(N + 1);
    for(int i = 1; i <= N; ++i) {
        parents[i] = i;
    }

    int connectionCount = 0;
    int mstLen = 0;
    while(edges.size() > 0) {
        edge_t e = edges.front();
        edges.erase(edges.begin());

        int src = e.src;
        int dst = e.dst;
        int cost = e.cost;

        if(Find(src) != Find(dst)) {
            Union(src, dst);
            connectionCount++;
            mstLen += cost;
        }

        if(connectionCount == N - 1) {
            break;
        }
    }

    if(connectionCount == N - 1) {
        cout << LAN_SUM - mstLen << '\n';
    }
    else {
        cout << "-1\n";
    }
    
    return 0;
}

int Find(int n) {
    if(parents[n] == n) {
        return n;
    }

    return parents[n] = Find(parents[n]);
}

void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);

    parents[pa] = pb;
}
