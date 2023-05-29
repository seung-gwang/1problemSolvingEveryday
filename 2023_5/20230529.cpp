/*
https://school.programmers.co.kr/tryouts/83544/challenges
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct job {
    int priority;
    int location;
} job_t;

int solution(vector<int> priorities, int location) {
    queue<job_t> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); ++i) {
        int p = priorities[i];
        q.push({p, i});
        pq.push(p);
    }
    
    int executeCount = 0;
    while(!pq.empty()) {
        job_t curJob = q.front();
        q.pop();
        
        if(curJob.priority != pq.top()) {
            q.push(curJob);
            continue;
        }
        
        pq.pop();
        executeCount++;
        
        if(curJob.location == location) {
            break;
        }
    }
    
    
    
    return executeCount;
}