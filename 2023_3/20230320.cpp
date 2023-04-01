#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#define INF (50000000)
using namespace std;

long A[101][101];

int N, M;

int main() {
    cin >> N >> M;

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            A[i][j] = i == j ? 0 : INF;
        }
    }

    for(int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        A[a][b] = min(A[a][b],(long)c);
    }

    for(int k = 1; k <= N; ++k) {
        for(int s = 1; s <= N; ++s) {
            for(int e = 1; e <= N; ++e) {
                A[s][e] = min(A[s][e], A[s][k] + A[k][e]);
            }
        }
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(A[i][j] == INF) {
                cout << 0 << ' ';
            }
            else {
                cout << A[i][j] << ' ';
            }
            
        }
        cout << '\n';
    }


}
