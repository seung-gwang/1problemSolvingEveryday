/*
https://www.acmicpc.net/problem/1256
*/
#include <iostream>
#include <vector>
#include <string>
#define K_MAX (1000000000)
typedef unsigned long long ull;
using namespace std;

ull N, M, K;
ull A, Z;
ull C[101][101];
ull D[202][202];
ull F[201];

void Solve() {
    cin >> N >> M >> K;
    A = N;
    Z = M;

    for (ull i = 0; i <= 200; ++i) {
        for (ull j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                D[i][j] = 1;
            }
            else {
                D[i][j] = D[i - 1][j - 1] + D[i - 1][j];

                if (D[i][j] > K_MAX) {
                    D[i][j] = K_MAX + 1;
                }
            }
        }
    }

    for (ull a = 0; a <= 100; ++a) {
        for (ull z = 0; z <= 100; ++z) {
            C[a][z] = D[a + z][z];
        }
    }

    string answer = "";
    if (C[A][Z] < K) {
        answer = "-1";
        goto PRINT_ANSWER;
    }

    while (A != 0 || Z != 0) {
        if (A >= 1 && K <= C[A - 1][Z]) { //a선택
            answer += 'a';
            A--;
        }
        else {
            K -= C[A - 1][Z]; //앞에 aXXXX 꼴의 문자열이 위치할 것. 그 총 개수는 A + Z -1개 
            answer += 'z';
            Z--;
        }
    }

PRINT_ANSWER:
    cout << answer << endl;
}

int main() {
    Solve();
    return 0;
}