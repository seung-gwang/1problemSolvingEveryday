/*
https://school.programmers.co.kr/learn/courses/30/lessons/42883
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    const int targetLen = number.length() - k;
    int startIdx = 0;

    //"417725 2841", 4 => targetLen : 6
    for (int i = 0; i < targetLen; i++) {
        char m = '0' - 1;
        int temp = -1;
        for (int j = startIdx; j <= k + i; j++) {//적어도 뒤에 남겨야 할 숫자 개수는 남겨두고 최대값 탐색
            if (m < number[j]) {
                m = number[j];
                temp = j;

                if (number[j] == '9') {
                    goto ADD_DIGIT;
                }
            }
        }
ADD_DIGIT:
        startIdx = temp + 1;
        answer += m;
    }
    
    return answer;
}
