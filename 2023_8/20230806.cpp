/*
https://school.programmers.co.kr/learn/courses/30/lessons/181929
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int sum = 0;
    int times = 1;
    for(const auto& i : num_list) {
        sum += i;
        times *= i;
    }
    
    if(sum * sum > times) {
        answer = 1;
    }
    
    return answer;
}