/*
https://school.programmers.co.kr/learn/courses/30/lessons/181944
*/
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    cout << n;
    if(n % 2) {
        cout << " is odd";
    }
    else {
        cout << " is even";
    }
    
    return 0;
}