/*
https://www.acmicpc.net/problem/11048
*/
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int MAP[1000][1000];
int DP[1000][1000];

void Solve();

int main() {
    Solve();
    return 0;
}

void Solve() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> MAP[i][j];
            DP[i][j] = 0;
        }
    }

    DP[0][0] = MAP[0][0];

    //used move right
    for (int cy = 0; cy < N; ++cy) {
        for (int cx = 0; cx < M; ++cx) {
            int ny = cy;
            int nx = cx + 1;
            if (ny < N && nx < M) {
                DP[ny][nx] = max(DP[ny][nx], MAP[ny][nx] + DP[cy][cx]);
            }
            

            ny = cy + 1;
            nx = cx + 1;
            if (ny < N && nx < M) {
                DP[ny][nx] = max(DP[ny][nx], MAP[ny][nx] + DP[cy][cx]);
            }

            ny = cy + 1;
            nx = cx;
            if (ny < N && nx < M) {
                DP[ny][nx] = max(DP[ny][nx], MAP[ny][nx] + DP[cy][cx]);
            }

            
        }
    }

    cout << DP[N - 1][M - 1] << endl;


}