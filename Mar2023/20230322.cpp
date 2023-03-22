/*
https://www.acmicpc.net/problem/11657
*/

/*
문제 정의
노드 N개
에지 M개 : src -> dst : 비용 cost : A, B, C
A, B : 1~N
C : -10000 ~ 10000

'벨만 포드'
음수 사이클 없으면 최단 거리들을 출력 (1번 도시가 출발 도시)
음수 사이클 있으면 '-1' 출력
*/
#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

typedef struct edge {
    int src;
    int dst;
    long long cost;
} edge_t;

vector<edge_t> edgeList;
vector<long long> D;
int N;
int M;


void Sol();
int UpdateDistance();

int main() {
    Sol();
    return 0;
}

void Sol() {

    cin >> N >> M; //도시 개수, 버스 노선 개수
    edgeList.resize(M);
    D.resize(N + 1); // 0 1 2 3 4 ... N

    for (int i = 0; i < M; ++i) {
        int A, B;
        long long C;
        cin >> A >> B >> C;
        edgeList[i] = edge_t{ A, B, C };
    }

    D[1] = 0;
    for (int j = 2; j <= N; ++j) {
        D[j] = LLONG_MAX;
    }

    //(노드 수 - 1) 번 업데이트
    for (int k = 1; k <= N - 1; ++k) {
        UpdateDistance();
    }

    //한번 더 업데이트 -> 실제 업데이트가 일어난다면 -1 출력, 아니면 D 전체 출력

    if (UpdateDistance() != 0) {
        cout << "-1\n";
    }
    else {
        for (int d = 2; d <= N; ++d) {
            if (D[d] == LLONG_MAX) {
                cout << "-1";
            }
            else {
                cout << D[d];
            }

            cout << '\n';

        }

    }
}

int UpdateDistance() {
    int updateCount = 0;
    for (int s = 1; s <= N; ++s) {
        //출발점이 '도착 가능한 지점' 이라면, 즉 직전 '노드 사용 횟수'를 소진하여 도착할 수 있는 곳이라면
        if (D[s] != LLONG_MAX) {
            for (int i = 0; i < edgeList.size(); ++i) {
                if (edgeList[i].src == s) {//출발점이 해당 노드인 곳에 대해
                    if (D[s] + edgeList[i].cost < D[edgeList[i].dst]) { //그 노드에서 cost를 소진하여 더 낮은 비용으로 도착 가능하면 업데이트
                        D[edgeList[i].dst] = D[s] + edgeList[i].cost;
                        updateCount++;
                    }
                }
            }

        }
    }
    return updateCount;
}

