/*
https://www.acmicpc.net/problem/1976
*/
#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;

int adj[201][201];
int parents[2010];

void Sol();
int FindParent(int n);
void Union(int a, int b);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Sol();
    return 0;
}

void Sol() {
    //initialize global var
    memset(adj, 0, sizeof(int) * 201 * 201);
    memset(parents, 0, sizeof(int) * 201);

    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; ++i) {
        parents[i] = i;
        for(int j = 1; j <= N; ++j) {
            cin >> adj[i][j];
        }
    }

    for(int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if(adj[i][j] == 1) {
                Union(i,j);
            }
        }
    }

    int city;
    cin >> city;

    const int ROOT = FindParent(city);

    bool isAvailable = true;
    for(int k = 1; k < M; ++k) {
        cin >> city;
        if(ROOT != FindParent(city)) {
            isAvailable = false;
            break;
        }
    }

    if(isAvailable) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }

}

void Union(int a, int b) {//b의 parents를 a의 parents로 변경
    int p = FindParent(a);
    parents[FindParent(b)] = p;
}

int FindParent(int n) {
    if(parents[n] != n) {
        int r = FindParent(parents[n]);
        parents[n] = r;
        return r;
    }

    return n;
}

