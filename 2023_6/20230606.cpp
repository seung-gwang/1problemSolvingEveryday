/*
https://school.programmers.co.kr/tryouts/83580/challenges
'가장 먼 노드'
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> A;
vector<int> V;
int N;
int ans;

void BFS();

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    N = n;
    A.clear();
    A.resize(n + 1);
    for(const auto& e : edge) {
        int n1 = e[0];
        int n2 = e[1];    
        /*make adjecent list*/
        A[n1].push_back(n2);
        A[n2].push_back(n1);
    }
    
    BFS();
    
    return ans;
}

void BFS() {
    vector<bool> visit(N + 1, false);
    queue<int> q;
    
    q.push(1);
    visit[1] = true;
    
    while(!q.empty()) {
        int popCount = q.size();
        ans = popCount;
        
        for(int i = 0; i < popCount; ++i) {
            int cur = q.front();
            q.pop();

            for(const auto& next : A[cur]) {
                if(visit[next]) { continue; }
                visit[next] = true;
                q.push(next);
            }   
        }
        
    }
}