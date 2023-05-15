/*
https://school.programmers.co.kr/learn/courses/30/lessons/12927
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<long long, vector<long long>> pq;
    for(const auto& w : works) {
        pq.push(w);
    }
    
    int time = n;
    while(time--) {
        int largest = pq.top();
        pq.pop();
        pq.push(largest - 1);
    }
    
    answer = 0;
    while(!pq.empty()) {
        int w = pq.top();
        pq.pop();
        if(w > 0) {
            answer += w * w;
        }
    }
    return answer;
}