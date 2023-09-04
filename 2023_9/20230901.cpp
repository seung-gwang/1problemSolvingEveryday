/*
https://school.programmers.co.kr/learn/courses/30/lessons/42861
*/
#include <vector>
#include <queue>
using namespace std;

vector<int> parent;
int getParent(const int island) {
    if(parent[island] == island) {
        return island;
    }
    else {
        return parent[island] = getParent(parent[island]);
    }
}

int solution(int n, vector<vector<int>> costs) {
    parent.resize(n);
    for(int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    for(const auto& c : costs) {
        pq.push({c[2],c[0],c[1]});
    }
    
    int answer = 0;
    int bridgeCnt = 0;
    
    while(true) {
        int a = pq.top()[1];
        int b = pq.top()[2];
        
        int ap = getParent(a);
        int bp = getParent(b);
        
        if(ap != bp) {
            answer += pq.top()[0];
            parent[ap] = bp;
            if(++bridgeCnt == n-1) {
                break;
            }
        }
        
        pq.pop();
    }
    
    return answer;
}