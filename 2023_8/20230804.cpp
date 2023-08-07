/*
https://school.programmers.co.kr/learn/courses/30/lessons/181941
*/

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    for(const auto& a : arr) {
        answer += a;
    }
    return answer;
}