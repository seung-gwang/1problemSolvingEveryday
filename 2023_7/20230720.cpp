/*
https://school.programmers.co.kr/learn/courses/30/lessons/172928
*/
#include <string>
#include <vector>

using namespace std;
char map[51][51];
int R;
int C;
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    R = park.size();
    C = park[0].length();
    
    pair<int, int> start;
    for(int r = 0; r < R; ++r) {
        for(int c = 0; c < C; ++c) {
            if(park[r][c] == 'S') {
                start = {r,c};
            }
            map[r][c] = park[r][c];
        }
    }
    
    int cy = start.first;
    int cx = start.second;
    int dy[] = {-1,1,0,0}; //상하좌우 NSWE
    int dx[] = {0,0,-1,1};
    for(const auto& route : routes) {
        int dist = route[2] - '0';
        
        int dir;
        if(route[0] == 'N') {
            dir = 0;
        }
        else if (route[0] == 'S') {
            dir = 1;
        }
        else if(route[0] == 'W') {
            dir = 2;
        }
        else if(route[0] == 'E') {
            dir = 3;
        }
        
        int ny = cy;
        int nx = cx;
                
        for(int i = 1; i <= dist; ++i) {
            ny = cy + dy[dir] * i;
            nx = cx + dx[dir] * i;
            
            if(ny < 0 || nx < 0 || ny > R - 1 || nx > C - 1 || map[ny][nx] == 'X') {
                goto SKIP_COMMAND;
            }
            ny = cy;
            nx = cx;
        }
        
        cy = cy + dy[dir] * dist;
        cx = cx + dx[dir] * dist;
        
SKIP_COMMAND:
        continue;
    }
    
    answer = {cy, cx};
    return answer;
}