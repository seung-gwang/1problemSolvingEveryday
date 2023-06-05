/*
https://school.programmers.co.kr/tryouts/83547/challenges
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
    
    
    bool failed = false;
    while(pq.top() < K && pq.size() >= 2) {
        int min1 = pq.top();
        pq.pop();
        
        int min2 = pq.top();
        pq.pop();
        
        int mix = min1 + min2 * 2;
        pq.push(mix);
        answer++;
    }
    
    if(pq.top() < K) {answer = -1;}
    return answer;
}