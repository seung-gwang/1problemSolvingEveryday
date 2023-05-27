/*
https://school.programmers.co.kr/tryouts/83543/challenges?language=cpp
*/
#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> pstack;
    for(const auto& p : s) {
        if(p == '(') {
            pstack.push(p);
        }
        else if(pstack.empty() == false) {
            pstack.pop();
        }
        else {
            answer = false;
            break;
        }
    }
    
    if(pstack.empty() == false) {
        answer = false;
    }
    
    return answer;
}