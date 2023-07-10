/*
https://school.programmers.co.kr/learn/courses/30/lessons/68644
*/
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    for(int i = 0; i < numbers.size() - 1; ++i) {
        for (int j = i + 1; j < numbers.size(); ++j) {
            s.insert(numbers[i] + numbers[j]);
        }
    }
    
    for(const auto& val : s) {
        answer.push_back(val);
    }
    
    return answer;
}