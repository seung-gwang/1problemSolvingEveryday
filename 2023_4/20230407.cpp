/*
https://www.acmicpc.net/problem/1010
*/
#include <iostream>
#include <vector>
using namespace std;

int T, N, M;
int D[30][30];

void Solve() {
    cin >> T;
    for(int t = 0; t < T; ++t) {
        cin >> N >> M; 
        //Get M combination N 
        for(int m = 1; m <= M; ++m) {
            D[m][0] = 1; //m개중에 아무것도 안고르는 경우는 1개
            D[m][1] = m; //m개중에 한개를 고르는 경우는 m개
            D[m][m] = 1; //m개중에 m개 다 고르는 경우는 1개
        }

        for(int m = 2; m <= M; ++m) { //m개중에
            for(int n = 1; n <= m; ++n) { //n개를 고름 (최대 m개 고르기 가능)
                D[m][n] = D[m - 1][n - 1] + D[m - 1][n];
            }
        }
        cout << D[M][N] << '\n';
    }
    
}

int main() {
    Solve();
    return 0;
}