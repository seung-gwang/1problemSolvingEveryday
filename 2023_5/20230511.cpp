/*
https://www.acmicpc.net/problem/25305
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

void Solve();
int main() {
    Solve();
    return 0;
}

void Solve() {
    cin >> N >> K;
    vector<int> scores(N);
    for(int i = 0; i < N; ++i) {
        int s;
        cin >> s;
        scores[i] = s; 
    }
    sort(scores.begin(), scores.end());
    
    cout << scores[N - K] << '\n';
}
