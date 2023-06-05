/*
https://school.programmers.co.kr/tryouts/83553/challenges?language=cpp
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int a = -1;
    int b = -1;
    
    for(const auto& sz : sizes) {
        int s = min(sz[0], sz[1]); //긴쪽
        int l = max(sz[0], sz[1]); //짧은쪽
        a = max(a, s);
        b = max(b, l);
    }
    
    return a*b;
}