/*
https://www.acmicpc.net/problem/18352
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> A;
vector<bool> visit;

int sol() {
    int N, M, K, X;
    cin >> N >> M >> K >> X;

    A.resize(N + 1);
    visit.resize(N + 1);
    for(int i = 0; i < N + 1; ++i) {
        A[i].clear();
        visit[i] = false;
    }

    for(int j = 0; j < M; ++j) {
        int src, dst;
        cin >> src >> dst;
        A[src].push_back(dst);
    }

    //BFS
    queue<int> q;
    q.push(X);
    visit[X] = true;

    int distance = 0;

    for(int dist = 0; dist < K; ++dist) {
        int count = q.size();

        for(int n = 0; n < count; ++n) {
            int cur = q.front();
            q.pop();

            for(int next : A[cur]) {
                if(visit[next] == false) {
                    visit[next] = true;
                    q.push(next);
                }
            }
        }
    }

    if(q.size() == 0) {
        cout << "-1" << endl;
    }
    else {
        vector<int> print;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            print.push_back(node);
        }
        sort(print.begin(), print.end());

        for(int n : print) {
            cout << n << '\n';
        }

        cout << endl;
    }
    
    return 0;
}

int main() {
    sol();
    return 0;
}