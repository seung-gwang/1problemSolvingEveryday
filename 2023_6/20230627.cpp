/*
https://school.programmers.co.kr/learn/courses/30/lessons/43163
*/

#include <string>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;
vector<bool> visit;

bool isTransferable(const string begin, const string target) {
    const int N = target.length();
    int diff = 0;
    for(int i = 0; i < N; ++i) {
        if(begin[i] != target[i]) {
            diff++;
        }
        
        if(diff > 1) {
            return false;
        }
    }
    
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = INT_MAX;
    queue<string> q;
    q.push(begin);
    visit.clear();
    visit.resize(words.size(), false);
    
    int dist = 0;
    while(!q.empty()) {
        int popCount = q.size();
        while(popCount--) {
            string start = q.front();
            q.pop();
            
            if(start == target) {
                answer = dist;
                goto ret;
            }
            
            for(int i = 0; i < words.size(); ++i) {
                string w = words[i];
                if(!visit[i] && isTransferable(start, w)) {
                    q.push(w);
                    visit[i] = true;
                }
            }
            
        }
        dist++;
    }
    
    if(answer == INT_MAX) {
        answer = 0;
    }
    
ret:   
    return answer;
}