/*
https://school.programmers.co.kr/learn/courses/30/lessons/42842
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sqCount = brown + yellow;

    
    int ansX;
    int ansY;
    
    for(int x = yellow; x > 0; --x) {
        if(yellow % x != 0) {continue;}
            /*
            2x + 2y + 4 == brown
            x * y = yellow
            */
        int y = yellow / x;
        if(2 * x + 2 * y + 4 == brown) {
            ansX = x + 2;
            ansY = y + 2;
            break;
        }
    }
    
    return {ansX, ansY};
}