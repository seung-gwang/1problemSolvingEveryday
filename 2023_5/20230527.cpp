/*
https://school.programmers.co.kr/tryouts/83542/challenges
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    const int numTask = progresses.size();
    
    for(int i = 0; i < numTask; ++i) {
        int p = progresses[i];
        int s = speeds[i];
        
        int d = (100 - p) / s;
        if(d * s + p < 100) {
            d++;
        }
        
        q.push(d);
    }
    
    //5 10 1 1 20 1 -> 1 3 2
    while(!q.empty()) {
        int cnt = 1;
        int maxVal = q.front();
        q.pop();
        
        while(!q.empty() && maxVal >= q.front()) {
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}