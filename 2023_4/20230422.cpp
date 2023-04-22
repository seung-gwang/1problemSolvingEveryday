/*
https://www.acmicpc.net/problem/18185
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int toBuy[10001];

int answer = 0;

int main() {
    int N;

    // input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> toBuy[i];
    }
    

    
    for (int i = 1; i <= N; i++) {
        if (toBuy[i + 1] > toBuy[i + 2]) {
            int count = min(toBuy[i], toBuy[i + 1] - toBuy[i + 2]);
            answer += 5 * count;

            toBuy[i] -= count;
            toBuy[i + 1] -= count;

            int count2 = min(toBuy[i], min(toBuy[i + 1], toBuy[i + 2]));
            answer += 7 * count2;

            toBuy[i] -= count2;
            toBuy[i + 1] -= count2;
            toBuy[i + 2] -= count2;
        }
        else {
            int count = min(toBuy[i], min(toBuy[i + 1], toBuy[i + 2]));
            answer += 7 * count;

            toBuy[i] -= count;
            toBuy[i + 1] -= count;
            toBuy[i + 2] -= count;

            int count2 = min(toBuy[i], toBuy[i + 1]);
            answer += 5 * count2;

            toBuy[i] -= count2;
            toBuy[i + 1] -= count2;
        }
        answer += 3 * toBuy[i];
        toBuy[i] = 0;
    }

    cout << answer << '\n';
}