/*
https://school.programmers.co.kr/tryouts/83541/challenges
*/
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    for(const auto& a : arr) {
        if(q.empty() || q.back() != a) {
            q.push(a);
        }
    }
    
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        answer.push_back(temp);
    }

    return answer;
}