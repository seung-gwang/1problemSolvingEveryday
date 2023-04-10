/*
https://www.acmicpc.net/problem/9095
*/
#include <iostream>
#include <vector>
using namespace std;

int T;
int N;

void Solve();
int count_ways(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

void Solve() {
    cin >> T;
    for(int i = 0; i < T; ++i) {
        cin >> N;
        cout << count_ways(N) << '\n';
    }

}

int main() {
    Solve();
    return 0;
}