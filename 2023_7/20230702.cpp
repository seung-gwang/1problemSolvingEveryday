/*
https://school.programmers.co.kr/learn/courses/30/lessons/155652
*/
#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    set<char> sset;
    for(const auto& c : skip) {
        sset.insert(c);
    }
    
    for(const auto& ss : s) {
        int n = index;
        char d = ss;
        while(n > 0) {
            if(++d > 'z') {
                d = 'a';
            }
            
            if(sset.find(d) == sset.end()) {
                n--;
            }
        }
        answer += d;
    }
    return answer;
}