/*
https://www.acmicpc.net/problem/2193
*/
#include <iostream>
#include <vector>
#define MAX_N (90)
typedef unsigned long long ull;

using namespace std;

int N;
ull DP0[MAX_N + 1];//N자리 이친수 중에 0으로 끝나는 것 개수
ull DP1[MAX_N + 1];//N자리 이친수 중에 1로 끝나는 것 개수

void Solve();
int main() {
    Solve();
    return 0;
}

void Solve() {
    cin >> N;
    
    DP0[1] = 0;//
    DP1[1] = 1;//1

    DP0[2] = 1;//10
    DP1[2] = 0;//

    DP0[3] = 1;//100 : DP0[N-1] + DP1[N-1]
    DP1[3] = 1;//101 "DP0[N-1]"

    for(int i = 4; i <= N; ++i) {
        DP0[i] = DP0[i - 1] + DP1[i - 1];
        DP1[i] = DP0[i - 1];
    }

    cout << DP0[N] + DP1[N] << '\n';
}