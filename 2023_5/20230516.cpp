/*
https://www.acmicpc.net/problem/2075
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> pq;
void Solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (!pq.empty()) {
        pq.pop();
    }
    Solve();
    return 0;
}

void Solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    for (int i = 0; i < N * N - N; ++i) {
        int temp;
        cin >> temp;

        int top = pq.top();
        pq.pop();
        int push = temp > top ? temp : top;
        pq.push(push);
    }

    cout << pq.top() << '\n';
}
