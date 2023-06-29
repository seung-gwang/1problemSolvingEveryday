/*
https://school.programmers.co.kr/learn/courses/30/lessons/42862
*/
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    set<int> common;
    for(int l : lost) {
        for(int r : reserve) {
            if(l == r) {
                common.insert(r);
            }
        }
    }
    
    set<int> ll;
    set<int> rr;
    
    for(int l : lost) {
        if(common.find(l) == common.end()) {
            ll.insert(l);
        }
    }
    
    for(int r : reserve) {
        if(common.find(r) == common.end()) {
            rr.insert(r);
        }
    }
    
    int cnt = 0;
    for(const auto& l : ll) {
        if(rr.find(l - 1) != rr.end()) {
            rr.erase(l - 1);
            cnt++;
            continue;
        }
        
        if(rr.find(l + 1) != rr.end()) {
            rr.erase(l + 1);
            cnt++;
        }
    }
    
    return n - ll.size() + cnt;
    
    return answer;
}