/*
https://school.programmers.co.kr/learn/courses/30/lessons/43162
*/
#include <vector>

using namespace std;
int A[200][200];
int V[200];
int N;

void DFS(const int cur) {
    for(int next = 0; next < N; ++next) {
        if(cur == next || A[cur][next] == 0 || V[next]) {continue;}
        V[next] = true;
        DFS(next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    for(int i = 0; i < N; ++i) {
        V[i] = false;
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            A[i][j] = computers[i][j];
        }
    }
    
    for(int i = 0; i < N; ++i) {
        if(V[i] == false) {
            V[i] = true;
            DFS(i);
            answer++;
        }
    }
    
    return answer;
}