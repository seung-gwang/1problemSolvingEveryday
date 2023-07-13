/*
https://school.programmers.co.kr/learn/courses/30/lessons/12913
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_max(const int a, const int b, const int c) {
    int ret = a > b ? a :b;
    ret = ret > c ? ret : c;
    return ret;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int N = land.size();
    vector<vector<int>> DP = land;
    for(int i = 0; i < DP.size(); ++i) {
        for(int j = 0; j < 4; ++j) {
            DP[i][j] = 0;
        }
    }
    
    DP[0][0] = land[0][0];
    DP[0][1] = land[0][1];
    DP[0][2] = land[0][2];
    DP[0][3] = land[0][3];
        
    for(int i = 1; i < N; ++i) {
        DP[i][0] = get_max(DP[i-1][1], DP[i-1][2], DP[i-1][3]) + land[i][0];
        DP[i][1] = get_max(DP[i-1][0], DP[i-1][2], DP[i-1][3]) + land[i][1];
        DP[i][2] = get_max(DP[i-1][0], DP[i-1][1], DP[i-1][3]) + land[i][2];
        DP[i][3] = get_max(DP[i-1][0], DP[i-1][1], DP[i-1][2]) + land[i][3];
    }
    
    answer = max(DP[N-1][0], DP[N-1][1]);
    answer = max(answer, DP[N-1][2]);
    answer = max(answer, DP[N-1][3]);
    
    return answer;
}