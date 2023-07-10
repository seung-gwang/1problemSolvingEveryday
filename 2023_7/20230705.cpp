/*
https://school.programmers.co.kr/learn/courses/30/lessons/178871
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<int, string> rank_name;
    unordered_map<string, int> name_rank;
    
    for(int i = 0; i < players.size(); ++i) {
        rank_name.insert({i, players[i]});
        name_rank.insert({players[i], i});
    }
    
    for(const auto& c : callings) {
        int r = name_rank[c]; //현재 불린 선수의 등수
        string frontName = rank_name[r-1]; //원래 앞 선수 (추월 당할 사람 이름)
        
        name_rank[c] = r-1;
        name_rank[frontName] = r;
        
        rank_name[r] = frontName;
        rank_name[r-1] = c;
    }
    
    answer.resize(players.size());
    for(int i = 0; i < players.size(); ++i) {
        answer[i] = rank_name[i];
    }
    
    
    
    return answer;
}