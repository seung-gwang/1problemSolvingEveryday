/*
https://school.programmers.co.kr/tryouts/83550/challenges
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(const auto& c : commands) {
        int left = c[0] - 1;
        int right = c[1] - 1;
        int target = c[2] - 1; //idx
        
        vector<int> temp;
        for(int i = left; i <= right; ++i) {
            temp.push_back(array[i]);
        }
        
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[target]);
    }
    
    return answer;
}