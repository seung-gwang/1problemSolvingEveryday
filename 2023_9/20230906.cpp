/*
https://school.programmers.co.kr/learn/courses/30/lessons/43165
*/
#include <string>
#include <vector>

using namespace std;
vector<int> gnums;
int vSize;
int T;
int gAns;

void DFS(int curIdx, int result) {
    if(curIdx == vSize) {
        if(result == T) {
            gAns++;
        }
        return;
    }
    
    DFS(curIdx+1, result + gnums[curIdx]);
    DFS(curIdx+1, result - gnums[curIdx]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    gnums = numbers;
    vSize = gnums.size();
    T = target;
    
    gAns = 0;
    DFS(0, 0);
    
    return gAns;
}

