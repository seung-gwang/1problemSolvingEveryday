/*
https://www.acmicpc.net/problem/10872
*/
#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull N;
ull DP[13];

void Solve();

int main() {
    Solve();
    return 0;
}

void Solve() {
    cin >> N; //calculate N!
    DP[0] = 1;
    DP[1] = 1;
    for (ull i = 2; i <= N; ++i) {
        DP[i] = DP[i - 1] * i;
    }

    cout << DP[N] << '\n';
}