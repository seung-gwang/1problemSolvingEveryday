/*
https://school.programmers.co.kr/learn/courses/30/lessons/12978
*/
#include <iostream>
#include <vector>
#include <queue>
#define INF (9999999)

using namespace std;
typedef pair<int, int> weight_node;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<bool> v(N+1, false);
    vector<int> dist(N+1, INF);
    priority_queue<weight_node, vector<weight_node>, greater<>> pq; //dijkstra
    vector<vector<weight_node>> A(N+1); //Adjacent list
    for(const auto& r : road) {
        int s = r[0];
        int d = r[1];
        int w = r[2];
        A[s].push_back({w, d});
        A[d].push_back({w, s}); //양방향 그래프
    }
    
    pq.push({0,1}); //1번 마을에서 시작 : Dijkstra
    while(!pq.empty()) {
        weight_node src = pq.top();
        pq.pop();
        if(v[src.second] == true) {continue;}
        v[src.second] = true;
        dist[src.second] = min(dist[src.second], src.first);
        
        for(const auto& dst : A[src.second]) {
            if(!v[dst.second]) {
                pq.push({dist[src.second] + dst.first, dst.second});
            }
        }
    }
    
    for(int i = 1; i <= N; ++i) {
        if(dist[i] <= K) {answer++;}
    }
    

    return answer;
}