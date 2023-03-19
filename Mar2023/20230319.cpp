/*
https://www.acmicpc.net/problem/1219
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, M, start, finish;
typedef struct edge {
    int dst;
    long long cost;
} edge_t;

vector<vector<edge_t>> A;
vector<long long> sales; //매출 (도시에서 버는 돈)
vector<long long> revenues; //수익 (도시에서 버는 돈에서 이전 도시로부터 오는 비용 뺀 수익)

void Sol();
void UpdateRevenues(bool additional);

int main() {
    Sol();
    return 0;
}

void Sol() {
    cin >> N >> start >> finish >> M;
    A.clear();
    A.resize(N);
    revenues.resize(N);
    fill(revenues.begin(), revenues.end(), LLONG_MIN);
    revenues[start] = 0;
    
    sales.resize(N);

    for(int i = 0; i < M; ++i) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        A[src].push_back({dst, cost});
    }

    for(int j = 0; j < N; ++j) {
        cin >> sales[j];
    }

    revenues[start] = sales[start];

    for(int src = 0; src < N; ++src) {
        for(edge_t& next : A[src]) {
            long long dstRev = sales[next.dst];
            next.cost -= dstRev;
        }
    }

    //(도시 수 - 1) : start 도시로부터 임의의 도시는 최대 (n - 1)개의 도시를 거치면 나옴 (직선으로 쭉 이어진 경우 n-1)
    // start ->  X -> X -> fin : 4개의 도시, start에서 3개의 도시를 거치면 fin
    for(int u = 0; u < N - 1; ++u) {
        UpdateRevenues(false);
    }

    vector<long long> revCpy = revenues;

    //그 이후에 이루어지는 수익 갱신은 싸이클 때문에 이루어지는 것.
    for(int k = 0; k < 50; ++k) {
        UpdateRevenues(true);
    }

    if(revenues[finish] == LLONG_MIN) {
        cout << "gg\n";
    }
    else if (revCpy[finish] < revenues[finish]) {
        cout << "Gee\n";
    }
    else {
        cout << revCpy[finish] << '\n';
    }

}

void UpdateRevenues(bool additional) {
    for(int i = 0; i < N; ++i) {
        if(revenues[i] != LLONG_MIN) {

            for(edge_t next : A[i]) {

                int dst = next.dst;
                long long cost = next.cost;

                if(revenues[i] == LLONG_MAX) {
                    revenues[dst]= LLONG_MAX;
                    continue;
                }

                if(revenues[dst] < revenues[i] - cost) {
                    revenues[dst] = revenues[i] - cost;
                    
                    if(additional) { //추가 Update에서 이루어지는 최대값 갱신 -> Cycle에 의한 갱신 : 무한대 수익 가능
                        revenues[dst] = LLONG_MAX;
                    }
                }
                
            }
        }
    }
}