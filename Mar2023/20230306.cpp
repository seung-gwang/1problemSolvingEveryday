/*
https://school.programmers.co.kr/learn/courses/30/lessons/49189
*/

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> A;
vector<int> dist;
vector<bool> visit;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    /*전역변수 초기화*/
    A.resize(n + 1);
    for (vector<int>& a : A) {
        a.clear();
    }

    dist.resize(n + 1);
    fill(dist.begin(), dist.end(), 0);

    visit.resize(n + 1);
    fill(visit.begin(), visit.end(), false);


    //인접리스트 생성
    for (vector<int>& se : edge) {
        A[se[0]].push_back(se[1]);
        A[se[1]].push_back(se[0]);
    }

    visit[0] = true;
    dist[0] = -1;

    //BFS   
    queue<int> q;
    int len = 0;
    q.push(1);
    visit[1] = true;

    while (!q.empty()) {
        int qSize = q.size();

        for (int i = 0; i < qSize; ++i) {
            int cur = q.front();
            q.pop();
            dist[cur] = len;

            for (int next : A[cur]) {
                if (!visit[next]) {
                    visit[next] = true;
                    q.push(next);
                }
            }
        }
        len++;
    }

    int MAX_LEN = len - 1;

    answer = 0;
    for (int d : dist) {
        if (d == MAX_LEN) {
            answer++;
        }
    }

    return answer;
}