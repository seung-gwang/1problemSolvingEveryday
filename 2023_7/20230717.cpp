/*https://school.programmers.co.kr/learn/courses/30/lessons/176963*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> um;
    for(int i = 0; i < name.size(); ++i) {
        um.insert({name[i], yearning[i]});
    }
    for(const auto& p : photo) {
        int score = 0;
        for(const auto& s : p) {
            score += um[s];
        }
        answer.push_back(score);
    }
    return answer;
}