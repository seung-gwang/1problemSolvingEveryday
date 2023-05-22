/*
https://school.programmers.co.kr/tryouts/83536/challenges
*/
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, bool> um;
    for(const auto& n : nums) {
        if(um.find(n) == um.end()) {
            um.insert({n, true});
        }
    }
    
    int answer = min(nums.size() / 2, um.size());
    return answer;
}