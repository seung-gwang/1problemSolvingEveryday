/*
https://www.acmicpc.net/problem/13398
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define MAX_N (100000)
using namespace std;
typedef long long sll;

vector<sll> nums;
int N;
sll leftSum[MAX_N + 1];
sll rightSum[MAX_N + 1];

sll answer;

void Solve() {
    cin >> N;
    nums.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> nums[i];
    }


    leftSum[1] = nums[1];
    rightSum[N] = nums[N];
    answer = max(leftSum[1], rightSum[N]);
    for (int i = 2; i <= N; ++i) {
        leftSum[i] = max(leftSum[i - 1] + nums[i], nums[i]);
        rightSum[N - i + 1] = max(rightSum[N - i + 2] + nums[N - i + 1], nums[N - i + 1]);
        answer = max(answer, leftSum[i]);
    }

    
    for (int j = 2; j <= N - 1; ++j) {
        sll temp = leftSum[j - 1] + rightSum[j + 1];
        answer = max(answer, temp);
    }

    cout << answer << '\n';
}

int main() {
    Solve();
    return 0;
}