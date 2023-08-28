/*
https://school.programmers.co.kr/learn/courses/30/lessons/86051
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool NUMS[10] = {false,};
    for(int n : numbers) {
        NUMS[n] = true;
    }
    for(int i = 0; i <= 9; ++i) {
        if(NUMS[i] == false) {
            answer += i;
        }
    }
        
    return answer;
}