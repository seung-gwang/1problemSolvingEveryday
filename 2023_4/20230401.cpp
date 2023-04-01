/*
https://www.acmicpc.net/problem/1068
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int D;
int root;
int answer;
vector<vector<int>> childs;
vector<bool> visited;
vector<int> roots;

void DFS(int node);


int Sol() {
    cin >> N;
    childs.clear();
    childs.resize(N);
    visited.resize(N);
    roots.clear();
    for (int i = 0; i < N; ++i) {
        int parent;
        cin >> parent;

        if (parent == -1) { 
            //root = i;
            roots.push_back(i);
            continue; 
        }

        childs[parent].push_back(i);
        visited[i] = false;
    }


    cin >> D;
   
    answer = 0;
    for (int r : roots) {
        visited[r] = true;
        DFS(r);
    }
    
    cout << answer << '\n';
    return 0;
}

int main() {
    Sol();
    return 0;
}

void DFS(int node) {
    if (node == D) {
        return;
    }

    if (childs[node].size() == 0) {
        answer++;
        return;
    }

    for (int child : childs[node]) {
        
        if (child == D) {
            if (childs[node].size() == 1) {
                answer++;
            }
            continue;
        }
        
        if (!visited[child]) {
            visited[child] = true;
            DFS(child);
        }
    }
}