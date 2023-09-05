/*
https://school.programmers.co.kr/learn/courses/30/lessons/12951
*/
#include <string>
#include <vector>
​
using namespace std;
​
string solution(string s) {
    string answer = "";
    char mask = 0x20;
    for(char& c : s) {
        if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
            c |= mask;    
        }
    }
    
    const int LEN = s.length();
    
    if('a' <= s[0] && s[0] <= 'z') {
        s[0] &= ~mask;
    }
    
    for(int i = 1; i < LEN - 1; ++i) {
        if(s[i] == ' ' && ('a' <= s[i+1] && s[i+1] <= 'z')) {
            s[i+1] &= ~mask;
        }    
    }
     
    return s;
}