/*
https://school.programmers.co.kr/learn/courses/30/lessons/42898
*/
#include <string>
#include <vector>
#define DIV (1000000007)
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int map[101][101];
    for (int x = 1; x <= m; ++x) {
        for (int y = 1; y <= n; ++y) {
            map[x][y] = 0;
        }
    }

    for (const auto& p : puddles) {
        map[p[0]][p[1]] = -1;
    }

    map[1][1] = 1;
    for (int x = 1; x <= m; ++x) {
        for (int y = 1; y <= n; ++y) {
            if (map[x][y] == -1) { continue; } //물에 잠긴 지역
            int plx = x - 1; //previoius left x
            int ply = y; //previous left y

            if (plx >= 1 && ply >= 1 && plx <= m && ply <= n && map[plx][ply] != -1) {
                map[x][y] += map[plx][ply];
                map[x][y] %= DIV;
            }

            int pux = x; //previous up x
            int puy = y - 1; //previous up y

            if (pux >= 1 && puy >= 1 && pux <= m && puy <= n && map[pux][puy] != -1) {
                map[x][y] += map[pux][puy];
                map[x][y] %= DIV;
            }
        }
    }

    answer = map[m][n] % DIV;
    return answer;
}
