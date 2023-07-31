#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int board[101][101]; 
int land[101][101]; //-1 : 침수, 1 : 안전지역
int N;
int mmax;
int answer = 0;

void BFS(const int y, const int x);

void Solve() {
    mmax = 0;
    answer = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int temp;
            cin >> temp;
            board[i][j] = temp;
            mmax = max(mmax, temp);
        }
    }

    /*
    수위 : 0 ~ 최고높이 - 1 탐색
    가능한 모든 수위에 대해 물에 잠기는 지역과 안전한 지역을 표시 
    */
    for(int w = 0; w < mmax; ++w) { //w : water level
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                land[i][j] = board[i][j] > w ? 1 : -1;
            }
        }

        int cur = 0;
        for(int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (land[i][j] == 1) { //이미 visit -> 0으로 표시
                    BFS(i, j);
                    cur++;
                }
            }
        }
        
        answer = cur > answer ? cur : answer;
    }

    cout << answer << '\n';
}

int main() {
    Solve();
    return 0;
}

void BFS(const int y, const int x) {
    const int dy[] = { -1,1,0,0 }; //상하좌우
    const int dx[] = { 0,0,-1,1 }; 

    land[y][x] = 0;
    queue<pair<int, int>> q;
    q.push({ y, x });
    while (!q.empty()) {
        int popCnt = q.size();
        while(popCnt--) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();

            for(int dir = 0; dir < 4; ++dir) { /*direction : 상하좌우*/
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];

                if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1 || land[ny][nx] != 1) {
                    continue;
                }

                land[ny][nx] = 0;
                q.push({ ny, nx });
            }
        }
    }
}