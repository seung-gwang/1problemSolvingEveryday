/*
https://www.acmicpc.net/problem/11726
*/
#include <iostream>
#define DIV (10007)
typedef unsigned long long ull;
using namespace std;

int N;
ull DP[1001];

void Solve() {
    cin >> N;

    DP[1] = 1;
    DP[2] = 2;
    
    for(int i = 3; i <= N; ++i) {
        DP[i] = (DP[i - 1] + DP[i - 2]) % DIV;

    }
    cout << DP[N] % DIV << '\n';
}

int main () {
    Solve();
    return 0;
}

