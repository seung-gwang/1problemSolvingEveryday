/*
https://www.acmicpc.net/problem/1328
*/
#include <iostream>
using namespace std;

static int N, L, R;
static long mod = 1000000007;
static long D[101][101][101];

int main() {
    cin >> N >> L >> R;
    D[1][1][1] = 1;

    for(int i = 2; i <= N; ++i) {
        for(int j = 1; j <= L; ++j) {
            for(int k = 1; k <= R; ++k) {
                D[i][j][k] = (D[i - 1][j][k] * (i - 2) + (D[i-1][j][k - 1] + D[i-1][j-1][k])) % mod;

            }

        }

    }

    cout << D[N][L][R] << '\n';
}