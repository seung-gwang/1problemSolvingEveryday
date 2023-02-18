/*
2023-02-18 PS
https://school.programmers.co.kr/learn/courses/30/lessons/77485
*/
#include <string>
#include <vector>
#include <queue>
#include <limits.h>

typedef struct space{
    int num;
    int r;
    int c;
}space_t;
using namespace std;

int board[101][101];


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int num = 1;
    for (int r = 1; r <= rows; ++r) {
        for (int c = 1; c <= columns; ++c) {
            board[r][c] = num++;
        }
    }

    for (vector<int> qr : queries) {
        int r1 = qr[0];
        int c1 = qr[1];
        int r2 = qr[2];
        int c2 = qr[3];
        const int size = 2 * (r2 - r1 - 1) + 2 * (c2 - c1 - 1) + 4;

        vector<space_t> q;

        //r1, c1부터 시계방향으로 push 큐
        int pushCount = 0;
        for (int c = c1; c < c2; ++c) {
            q.push_back({ board[r1][c], r1, c });
            pushCount++;
            
        }

        for (int r = r1; r < r2; ++r) {
            q.push_back({ board[r][c2], r, c2 });
            pushCount++;
        }

        for (int c = c2; c > c1; --c) {
            q.push_back({ board[r2][c], r2, c });
            pushCount++;
        }

        for (int r = r2; r > r1; --r) {
            q.push_back({ board[r][c1], r, c1 });
            pushCount++;
        }

        //회전
        int temp = q.back().num;
        for (int i = q.size() - 1; i > 0; --i) {
            q[i].num = q[i - 1].num;
        }
        q[0].num = temp;
       
        int ans = INT_MAX;
        for (space_t s : q) {
            board[s.r][s.c] = s.num;
            ans = min(ans, s.num);
        }
        
        answer.push_back(ans);
    }

    return answer;
}

