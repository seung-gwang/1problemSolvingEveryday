/*
https://school.programmers.co.kr/learn/courses/30/lessons/1844
*/
#include<vector>
#include <queue>
using namespace std;
typedef struct pos {int y; int x;} pos_t;

int solution(vector<vector<int> > maps)
{   
    int answer = 0;
    const int n = maps.size();
    const int m = maps[0].size();
    
    bool visit[101][101] = {false,};
    
    queue<pos_t> q;
    q.push(pos_t{0,0});
    visit[0][0] = true;
    
    bool found = false;
    int dist = 1;
    while(!q.empty()) {
        int popCnt = q.size();
        while(popCnt--) {
            pos_t cur = q.front();
            int cy = cur.y;
            int cx = cur.x;
            
            q.pop();
            
            if(cy == n-1 && cx == m-1) {
                return dist;
            }
            
            const int dy[] = {-1,1,0,0};
            const int dx[] = {0,0,-1,1};
            for(int dir = 0; dir < 4; ++dir) {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                
                if(ny < 0 || nx < 0 || ny >= n || nx >= m || maps[ny][nx]==0 || visit[ny][nx]) {
                    continue;
                }
                
                q.push(pos_t{ny,nx});
                visit[ny][nx] = true;
            }   
        }
        dist++;
    }
    

    return -1;
}