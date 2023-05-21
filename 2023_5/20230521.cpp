/*
https://www.acmicpc.net/problem/1026
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
vector<int> B;
int N;

void Solve();

int main() {
    Solve();
    return 0;
}

void Solve() {
    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());

    int answer = 0;
    for (int i = 0; i < N; ++i) {
        answer += A[i] * B[i];
    }

    cout << answer << '\n';



}