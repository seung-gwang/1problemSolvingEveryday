/*
https://school.programmers.co.kr/learn/courses/30/lessons/132266
*/
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#define MAX_N (100000)
using namespace std;
typedef pair<int, int> dist_node;
vector<vector<int>> A;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    /*
    총 지역 수 n, 지역번호 1~n
    부대 번호 = destination
    
    */
    A.clear();
    A.resize(n + 1);
    for(const auto& r : roads) {
        A[r[0]].push_back(r[1]);
        A[r[1]].push_back(r[0]);
    }
    
    vector<bool> visit(n+1, false);
    vector<int> dist(n+1, INT_MAX);
    priority_queue<dist_node, vector<dist_node>, greater<>> q;
    
    q.push({0, destination}); //djk
    while(!q.empty()) { 
        dist_node cur = q.top();
        q.pop();
        
        if(visit[cur.second]) {continue;}
        visit[cur.second] = true;
        dist[cur.second] = min(dist[cur.second], cur.first);
        
        for(int nextNode : A[cur.second]) {
            if(visit[nextNode]) {continue;}
            q.push({cur.first + 1, nextNode});
        }
    }
    
    vector<int> answer;
    for(const auto& s: sources) {
        if(dist[s] != INT_MAX) {
            answer.push_back(dist[s]);
        }
        else {
            answer.push_back(-1);
        }
    }
    
    return answer;
}