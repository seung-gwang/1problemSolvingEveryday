/*
https://www.acmicpc.net/problem/1300
*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> row;

int answer;
void sol() {
    int N, K;
    cin >> N >> K;

    int start = 1;
    int end = K;

    while (start <= end) {
        int mid = (start + end) / 2;
        int count = 0;

        for (int r = 1; r <= N; ++r) {
            count += min(N, mid / r);
        }

        if (count < K) {
            start = mid + 1;
        }
        else { // count >= K
            end = mid - 1;
            answer = mid;
        }
    }

    cout << answer << '\n';
}

int main() {
    sol();
    return 0;
}