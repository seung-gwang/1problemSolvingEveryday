/*
https://school.programmers.co.kr/learn/courses/30/lessons/181188
*/
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(const auto& t : targets) {
        pq.push(make_pair(t[0], t[1]));
    }
    
    int l = -1;
    int r = INT_MAX;
    
    answer++;
    while(!pq.empty()) {
        pair<int, int> front = pq.top();
        pq.pop();
        
        int cl = front.first;
        int cr = front.second;
        
        /*
        l   r
        cl cr
        */
        if(cl < r) { 
            l = max(l, cl);
            r = min(r, cr);
        }
        else {
            l = cl;
            r = cr;
            answer++;
        }
    }
    /*
    1 4
    3 7
    
    4 5
    4 8
    
    5 12
    10 14
    11 13
    
    */
    return answer;
}