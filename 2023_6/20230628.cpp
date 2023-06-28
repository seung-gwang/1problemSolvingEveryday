/*
https://school.programmers.co.kr/learn/courses/30/lessons/43105
Dynamic Programming
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    const int N = triangle.size();
    int answer = 0;
    vector<vector<int>> DP(N);
    for(int i = 0; i < N; ++i) {
        DP[i].resize(N, 0);
    }
    
    DP[0][0] = triangle[0][0];
    for(int i = 0; i < N - 1; ++i) { //각 층의
        for(int j = 0; j < i + 1; ++j) { //각 숫자에 대하여
            DP[i + 1][j] = max(DP[i + 1][j], DP[i][j] + triangle[i + 1][j]);
            DP[i + 1][j + 1] = max(DP[i + 1][j + 1], DP[i][j] + triangle[i+1][j+1]);
            
            answer = max(DP[i+1][j], answer);
            answer = max(DP[i+1][j+1], answer);
        }
    }
    
    
    
    return answer;
}