/*
https://school.programmers.co.kr/learn/courses/30/lessons/42748
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(const auto& c : commands) {
        vector<int> partial;
        for(int i = c[0]-1; i <= c[1]-1; ++i) {
            partial.push_back(array[i]);
        }
        
        sort(partial.begin(), partial.end());
        answer.push_back(partial[c[2] - 1]);
    }
    return answer;
}