/*
https://school.programmers.co.kr/tryouts/83537/challenges
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> um;
    for(const auto& c : completion) {
        if(um.find(c) != um.end()) {
            um[c]++;
        }
        else {
            um.insert({c, 1});    
        }
        
    }
    
    for(const auto& p : participant) {
        if(um.find(p) == um.end()) {
            answer = p;
            break;
        }
        else if(um[p] > 1) {
            um[p]--;
        }
        else {
            um.erase(p);
        }
    }
    
    return answer;
}