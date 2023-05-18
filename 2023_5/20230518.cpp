/*
https://school.programmers.co.kr/learn/courses/30/lessons/181945
*/
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(const auto& c : str) {
        cout << c << '\n';
    }
    return 0;
}