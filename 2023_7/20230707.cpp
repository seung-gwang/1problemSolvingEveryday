/*
https://school.programmers.co.kr/learn/courses/30/lessons/76501
*/
#include <string>
#include <vector>

using namespace std;
typedef long long sll;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 123456789;
    sll llAns = 0;
    for(int i = 0; i < absolutes.size(); ++i) {
        sll llVal = (sll)absolutes[i];
        if(!signs[i]) {
            llVal *= (-1);
        }
        llAns += llVal;
    }
    answer = (int)llAns;
    return answer;
}