/*
https://school.programmers.co.kr/learn/courses/30/lessons/72415
*/
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;

int gboard[4][4];

typedef struct coord {
    int y;
    int x;
}coord_t;

int BFS(coord_t src, coord_t dst);

int solution(vector<vector<int>> board, int r, int c) {
    int answer = INT_MAX;
  
    vector<vector<coord_t>> cardCoords(7); 

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            gboard[i][j] = board[i][j];
            if (board[i][j] != 0) {
                cardCoords[board[i][j]].push_back(coord_t{ i, j });
            }
        }
    }

    int gboardCpy[4][4];
    memcpy(gboardCpy, gboard, sizeof(int) * 4 * 4);
    
    vector<int> cards;
    for (int k = 1; k <= 6; ++k) {
        if (cardCoords[k].size() != 0) {
            cards.push_back(k);
        }
    }

    do {
        int count;
        coord_t dst;
        coord_t src;
        

        for (int bits = 0; bits < pow(2, cards.size()); ++bits) {

            vector<coord_t> order;
            order.push_back(coord_t{ r,c });
            count = cards.size() * 2; //엔터 두번씩은 눌러야 함.

            //A 카드 : A1, A2가 있으면, A1 -> A2 또는 A2 -> A1 순서로 방문 가능
            //greedy로 당장 가장 짧은 동선을 고르면 통과 못하는 TC 존재
            for (int sr = 0; sr < cards.size(); ++sr) {
                if ((((bits >> sr) & 1) == 1)) {
                    order.push_back(cardCoords[cards[sr]][0]);
                    order.push_back(cardCoords[cards[sr]][1]);

                }
                else {
                    order.push_back(cardCoords[cards[sr]][1]);
                    order.push_back(cardCoords[cards[sr]][0]);
                }
            }

            count += BFS(order[0], order[1]);
   
            for (int i = 1; i < order.size() - 1; ++i) {
                coord_t src = order[i];
                coord_t dst = order[i + 1];
                count += BFS(src, dst);
                gboard[src.y][src.x] = 0;
                gboard[dst.y][dst.x] = 0;
            }

            answer = min(count, answer);

            memcpy(gboard, gboardCpy, sizeof(int) * 4 * 4);
        }

    } while (next_permutation(cards.begin(), cards.end()));


    return answer;
}


int BFS(coord_t src, coord_t dst) {
    const int dy[4] = { -1, 1, 0, 0 }; //상하좌우
    const int dx[4] = { 0, 0, -1, 1 };

    int cost = 0;
    coord_t cur = src;
    bool visit[4][4] = { false, };

    queue<coord_t> bfsQ;
    bfsQ.push(cur);
    visit[cur.y][cur.x] = true;

    while (true) {
        int popCount = bfsQ.size();
        for (int i = 0; i < popCount; ++i) {
            coord_t temp = bfsQ.front();
            bfsQ.pop();

            if (temp.y == dst.y && temp.x == dst.x) {
                goto RETURN;
            }
            else {
                for (int dir = 0; dir < 4; ++dir) {
                    int ny = temp.y;
                    int nx = temp.x;

                    int ky = ny + dy[dir];
                    int kx = nx + dx[dir];

                    //ctrl 없는 방향키 이동
                    if (0 <= ky && ky < 4 && 0 <= kx && kx < 4 && gboard[ky][kx] == 0) {
                        bfsQ.push({ ky, kx });
                    }

                    //ctrl 있는 방향키 이동
                    while (true) {
                        ny += dy[dir];
                        nx += dx[dir];

                        //무효한 좌표까지 간다면 -> 해당 방향 유효한 가장 끝 좌표
                        if (ny < 0 || 4 <= ny || nx < 0 || 4 <= nx) {
                            bfsQ.push(coord_t{ ny - dy[dir], nx - dx[dir] });
                            break;
                        }
                        else if (gboard[ny][nx] != 0) {
                        //유효인 좌표이고 카드가 존재한다면 거기로 이동 가능
                            bfsQ.push(coord_t{ ny, nx });
                            break;
                        }
                    }
                }
            }
        }
        cost++;
    }

RETURN:
    return cost;
}

int main() {
    cout << solution({ {1, 0, 0, 3},{2, 0, 0, 0},{0, 0, 0, 2},{3, 0, 1, 0} }, 1, 0) << endl;
    cout << solution({ {3, 0, 0, 2},{0, 0, 1, 0},{0, 1, 0, 0},{2, 0, 0, 3} }, 0, 1) << endl;
    return 0;
}