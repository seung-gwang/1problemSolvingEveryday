/*
https://school.programmers.co.kr/learn/courses/30/lessons/72413
*/
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <limits.h>
int F[201][201];

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for (int i = 0; i <= 200; ++i) {
        for (int j = 0; j <= 200; ++j) {
            F[i][j] = i == j ? 0 : INT_MAX;
        }
    }

    for (const auto& f : fares) {
        int n1 = f[0];
        int n2 = f[1];
        int w = f[2];
        F[n1][n2] = w;
        F[n2][n1] = w;
    }

    
    for (int k = 1; k <= n; ++k) {
        for (int src = 1; src <= n; ++src) {
            for (int dst = 1; dst <= n; ++dst) {
                F[src][dst] = min(F[src][dst], F[src][k] + F[k][dst]);
            }
        }
    }
    
    answer = INT_MAX;
    for(int i = 1; i <= n; ++i) {//split
        answer = min(answer, F[s][i] + F[i][a] + F[i][b]);
    }

    return answer;
}