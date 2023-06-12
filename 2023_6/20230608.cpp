/*
https://school.programmers.co.kr/tryouts/83573/challenges

'게임 맵 최단거리'
*/
#include<vector>
#include <queue>

using namespace std;
int board[100][100];
int n; //row size
int m; //col size
int g_answer;
typedef pair<int, int> coord;

void BFS();

int solution(vector<vector<int> > maps)
{
    
    n = maps.size();
    m = maps[0].size();
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            board[i][j] = maps[i][j];
        }
    }
    
    BFS();
    
    return g_answer;
}

void BFS() {
    int dy[] = {-1,1,0,0};//상하좌우
    int dx[] = {0,0,-1,1};
    
    
    queue<coord> q;
    bool v[100][100] = {false,};
    
    q.push({0,0});
    g_answer = 1;
    v[0][0] = true;
    
    while(!q.empty()) {
        int popCount = q.size();
        g_answer++;
        while(popCount--) {
            coord cur = q.front();
            int cy = cur.first;
            int cx = cur.second;
            q.pop();
            
            for(int dir = 0; dir < 4; ++dir) {  
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }
                
                if(v[ny][nx] || board[ny][nx] == 0) {
                    continue;
                }
                
                
                
                v[ny][nx] = true;
                
                if(ny == n-1 && nx == m-1) {
                    return;
                }
                
                q.push({ny, nx});
                
            }
        }
        
    }
    
    g_answer = -1;
    return;
}

