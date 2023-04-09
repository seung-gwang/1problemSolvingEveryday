/*
https://www.acmicpc.net/problem/2644
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 전체 사람 수
int M; //관계 수
int P1,P2;
int chon;
int answer;

vector<vector<int>> A;
vector<bool> visit;

void DFS(int node) {
    int cur = node;

    if(cur == P2) {
        answer = chon;
        return;
    }

    for(int next : A[cur]) {
        if(visit[next]) {continue;}
        visit[next] = true;
        
        chon++;
        DFS(next);
        chon--;

    }
}

void Solve() {
    cin >> N;
    cin >> P1 >> P2; //촌수를 계산할 두 사람
    cin >> M; //관계의 개수


    A.clear();
    A.resize(N + 1);
    visit.resize(N + 1);
    fill(visit.begin(), visit.end(), false);

    for(int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
    }

    chon = 0;
    visit[P1] = true;
    DFS(P1);

    if(answer == 0) {answer = -1;}
    cout << answer << '\n';
}

int main() { Solve(); return 0;}