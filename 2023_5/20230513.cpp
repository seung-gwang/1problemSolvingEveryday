/*
https://www.acmicpc.net/problem/2587
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> N(5);

void Solve();
int main() {
    Solve();
}

void Solve() {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> N[i];
        sum += N[i];
    }

    sort(N.begin(), N.end());
    cout << sum / 5 << '\n';
    cout << N[2] << '\n';
}