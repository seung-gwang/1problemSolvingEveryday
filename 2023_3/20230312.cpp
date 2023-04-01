/*
https://www.acmicpc.net/problem/1325
*/
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> A;
vector<int> visit; //0 : not yet visited, 1, 2 Color
bool answer;

void DFS(int cur, int color);
void Sol();
void Subsol();

int main() {
    Sol();
}

void Sol() {
    int K;
    cin >> K;

    for(int k = 0; k < K; ++k) {
        Subsol();
    }
}

void Subsol() {
    int V, E;
    cin >> V >> E;

    A.resize(V + 1);
    visit.resize(V + 1);

    for(int i = 0; i < V + 1; ++i) {
        A[i].clear();
        visit[i] = 0;
    }

    for(int i = 0; i < E; ++i) {
        int src, dst;
        cin >> src >> dst;
        A[src].push_back(dst);
        A[dst].push_back(src);
    }

    answer = true;
    for(int cur = 1; cur <= V; ++cur) {
        if(visit[cur] == 0) {
            visit[cur] = 1;
            DFS(cur, 2);
        }
    }

    if(answer == true) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

void DFS(int cur, int color) {

    visit[cur] = color;
    int nextColor = color == 1 ? 2 : 1;
    for(int next : A[cur]) {
        if(visit[next] != 0 && visit[next] != nextColor) {
            answer = false;
            return;
        }
        else if(visit[next] == 0) {
            DFS(next, nextColor);
        }
    }
}
