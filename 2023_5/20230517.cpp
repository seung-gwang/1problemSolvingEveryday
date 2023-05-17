/*
https://school.programmers.co.kr/learn/courses/30/lessons/181949
*/
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); ++i) {
        str[i] ^= 0x20;
    }
    cout << str;
    return 0;
}