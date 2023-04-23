/*
https://www.acmicpc.net/problem/1915
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int M;
typedef pair<int, int> r_c;

int DP[1005][1005];
int sideLen;
void Solve();


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}

void Solve() {
    cin >> N >> M;
    sideLen = 0;
    for (int i = 0; i < N; ++i) {
        string nums;
        cin >> nums;
        for (int j = 0; j < M; ++j) {
            DP[i][j] = nums[j] - '0';
            
            if (DP[i][j] == 1 && j > 0 && i > 0) {
                DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1])) + DP[i][j];
            }

            sideLen = max(sideLen, DP[i][j]);
        }
    }

    cout << sideLen * sideLen << '\n';
}