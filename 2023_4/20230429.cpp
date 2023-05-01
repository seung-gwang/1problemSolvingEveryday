/*
https://www.acmicpc.net/problem/9252
*/
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

string a, b;
int DP[1001][1001];

void Solve();
int main() {
    Solve();
    return 0;
}

void Solve() {
    memset(DP, 0, sizeof(int) * 1001 * 1001);
    cin >> a;
    cin >> b;

    int aLen = a.length();
    int bLen = b.length();

    for(int i = 1; i <= aLen; ++i) {
        for(int j = 1; j <= bLen; ++j) {
            if(a[i - 1] != b[j - 1]) {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
            else {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
        }
    }

    string answerStr = "";
    int answerLen = DP[aLen][bLen];
    cout << answerLen << '\n';

    int i = aLen;
    int j = bLen;
    while(answerLen > 0) {
        if(a[i - 1] == b[j - 1]) {
            answerStr = a[i - 1] + answerStr;
            answerLen--;
            i--;
            j--;
        }
        else {
            if(DP[i - 1][j] > DP[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }

    cout << answerStr << '\n';
}