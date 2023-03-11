/*
https://www.acmicpc.net/problem/1325
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> A;
vector<bool> V;
vector<int> depths;

int maxSize;

int Sol();
void DFS(int cur, int& depth);

int main() {
    Sol();
}

int Sol() {
    int N, M;
    cin >> N >> M;

    A.resize(N + 1);
    V.resize(N + 1);
    depths.resize(N + 1);
    for(int i = 0; i < N + 1; ++i) {
        A[i].clear();
        V[i] = false;
        depths[i] = 0;
    }   

    for(int j = 0; j < M; ++j) {
        int src, dst;
        cin >> src >> dst;
        A[dst].push_back(src); //반대 방향으로 그래프 생성
    }

    int MAX_DEPTH = 0;
    
    for(int cur = 1; cur <= N ; ++cur) {
        fill(V.begin(), V.end(), false);
        V[cur] = true;
        int depth = 0;
        DFS(cur, depth);
        MAX_DEPTH = max(depth, MAX_DEPTH);
        depths[cur] = depth;
    }

    for(int node = 1; node <= N; ++node) {
        if(depths[node] == MAX_DEPTH) {
            cout << node << ' ';
        }
    }
    cout << endl;
    
    return 0;
}

void DFS(int cur, int& depth) {
    depth++;
    for(int next : A[cur]) {
        if(V[next] == false) {
            V[next] = true;
            DFS(next, depth);
        }
    }
}