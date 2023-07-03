/*
https://school.programmers.co.kr/learn/courses/30/lessons/43164?itm_content=course14743
'여행 경로'
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> answer;
unordered_map<string, vector<pair<string, bool>>> UT;
int numTicket;


void DFS(int ticketUseCnt, vector<string> route) {
    if (numTicket == ticketUseCnt) {
        if (answer.empty() || answer > route) {
            answer = route;
        }
        return;
    }

    for (auto& t : UT[route.back()]) {
        if (t.second) { //ticket already used
            continue;
        }
        t.second = true;
        vector<string> rCpy = route;
        rCpy.push_back(t.first);
        DFS(ticketUseCnt + 1, rCpy);
        t.second = false;
    }

 
}

vector<string> solution(vector<vector<string>> tickets) {
    numTicket = tickets.size();
    answer.clear();
    for (const auto& t : tickets) {
        string s = t[0];
        string e = t[1];
        UT[s].push_back({e, false});
    }

    for (auto& e : UT["ICN"]) {
        e.second = true;
        DFS(1, { "ICN", e.first });
        e.second = false;
    }

    return answer;
}