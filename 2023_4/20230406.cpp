/*
https://www.acmicpc.net/problem/2606
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M; //컴퓨터 수 (노드), 연결수 (edge)
int answer;

vector<vector<int>> A;
vector<int> visit;

void DFS(int node);
void Solve();

int main() {
    Solve();
    return 0;
}

void Solve() {
    cin >> N;
    cin >> M;

    A.clear();
    A.resize(N + 1);

    for(int i = 0; i < M; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        A[c1].push_back(c2);
        A[c2].push_back(c1);
    }

    visit.resize(N + 1);
    fill(visit.begin(), visit.end(), false);
    visit[1] = true;

    answer = 0;
    DFS(1);
    cout << answer << '\n';
}

void DFS(int node) {
    int cur = node;
    for(int next : A[cur]) {
        if(visit[next]) {continue;}
        visit[next] = true;
        answer++;
        DFS(next);
    }
}