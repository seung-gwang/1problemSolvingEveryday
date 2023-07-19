/*https://school.programmers.co.kr/learn/courses/30/lessons/138477*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<>> pq;
    
    for(const auto& s : score) {
        pq.push(s);
        
        while(pq.size() > k) {
            pq.pop();
        }
        
        answer.push_back(pq.top());
    }
    
    return answer;
}