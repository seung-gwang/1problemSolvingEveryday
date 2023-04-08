/*
https://www.acmicpc.net/problem/13251
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int N, M, K;
vector<int> counts;

void Solve() {
    counts.clear();
    cin >> M; //조약돌 색상 수
    N = 0;
    for(int i = 0; i < M; ++i) {
        int count;
        cin >> count;
        N += count;
        counts.push_back(count);
    }
    cin >> K;

    if(M == 1 || K == 1) {
        cout << "1.0";
        return;
    }

    double answer = 0.0;
    for(int c : counts) {
        int rock = c;
        double prob = 1.0;
        int div = N;

        if(rock < K) {continue;}

        for(int i = 0; i < K; ++i) {
            prob *= (double)rock / div;
            rock--; div--;
        }
        
        answer += prob;
    }
    cout << fixed;
    cout.precision(9);
    cout << answer;
}

int main() {
    Solve();
    return 0;
}