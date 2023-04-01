/*
https://www.acmicpc.net/problem/1389
*/

#include <iostream>
#include<memory.h>
#include <limits.h>
#include <algorithm>
#define INF (50000000)

using namespace std;

int N, M;
long A[101][101];

int main() {
    for(int i = 0; i < 101; ++i) {
        for(int j = 0; j < 101; ++j) {
            A[i][j] = i == j ? 0 : INF;
        }
    }

    cin >> N >> M;
    for(int m = 0; m < M; ++m) {
        int a, b;
        cin >> a >> b;
        A[a][b] = 1;
        A[b][a] = 1;
    }

    for(int k = 1; k <= N; ++k) {
        for(int src = 1; src <= N; ++src) {
            for(int dst = 1; dst <= N; ++dst) {
                A[src][dst] = min(A[src][dst], A[src][k] + A[k][dst]);
            }
        }
    }

    int answer = 1;
    long minVal = LONG_MAX;
    for(int n = 1; n <= N; ++n) {
        long sum = 0;
        for(int f = 1; f <= N; ++f) {
            if(A[n][f] == INF) {
                continue;
            }
            sum += A[n][f];
        }

        if(minVal > sum) {
            minVal = sum;
            answer = n;
        }
    }

    cout << answer << "\n";

    return 0;
}