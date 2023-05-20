/*
https://school.programmers.co.kr/learn/courses/30/lessons/42626
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for(const auto& s : scoville) {
        pq.push(s);
    }
    
    while(!pq.empty()) {
        if(pq.top() >= K) {
            break;
        }
        
        if(pq.size() >= 2) {
            int leastFirst = pq.top();
            pq.pop();
            int leastSecond = pq.top();
            pq.pop();
        
            pq.push(leastFirst + leastSecond *2);
            answer++;    
        }
        else {
            answer = -1;
            break;
        }
        
    }
    
    
    return answer;
}