/*
https://school.programmers.co.kr/learn/courses/30/lessons/134240
*/
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    for(int i = food.size() - 1; i > 0; --i) {
        for(int j = 0; j < food[i] / 2; ++j) {
            answer += to_string(i);
            answer = to_string(i) + answer;
        }
    }
    return answer;
}