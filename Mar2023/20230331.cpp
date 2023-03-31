/*
https://www.acmicpc.net/problem/11725
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<int> parents;
vector<vector<int>> A;
vector<bool> visit;

void Sol() {
    parents.clear();
    A.clear();
    visit.clear();

    cin >> N;
    parents.resize(N + 1);
    A.resize(N + 1);
    visit.resize(N + 1);
    fill(visit.begin(), visit.end(), false);

    for(int i = 0; i < N- 1; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        A[n1].push_back(n2);
        A[n2].push_back(n1);
    }

    visit[1] = true;
    queue<int> q;
    q.push(1);

    //BFS
    while(!q.empty()) {
        int popCount = q.size();

        for(int p = 0; p < popCount; ++p) {
            int cur = q.front();
            q.pop();

            for(int next : A[cur]) {
                if(visit[next] == true) { continue; }
                visit[next] = true;
                q.push(next);
                parents[next] = cur;
            }
        }
    }

    for(int n = 2; n <= N; ++n) {
        cout << parents[n] << '\n';
    }
}

int main() {
    Sol();
    return 0;
}