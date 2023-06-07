/*
https://school.programmers.co.kr/tryouts/83572/challenges
'네트워크'
*/
#include <string>
#include <vector>

using namespace std;
vector<bool> visit;
int N;
vector<vector<int>> A;
void DFS(const int cur);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    visit.resize(N);
    A.clear();
    A.resize(N);
    
    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            if(computers[i][j] == 1) {
                A[i].push_back(j);
                A[j].push_back(i);
            }
        }
    }
    
    for(int i = 0; i < n; ++i) {
        visit[i] = false;
    }
    
    int cnt = 0; 
    for(int i = 0; i < N; ++i) {
        if(visit[i] == false) {
            DFS(i);
            cnt++;
        }
    }
    
    return cnt;
}

void DFS(const int cur) {
    visit[cur] = true;
    for(const auto& next : A[cur]) {
        if(visit[next]) {
            continue;
        }
        visit[next] = true;
        DFS(next);
    }
}