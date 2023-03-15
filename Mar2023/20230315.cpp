/*
https://www.acmicpc.net/problem/2251
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<vector<int>> Adj = {
    {1, 2},
    {0, 2},
    {0, 1}
};

int A_MAX, B_MAX, C_MAX;
vector<int> answers;
map<vector<int>, int> casesMap;

void Sol();

int main() {
    Sol();
}

void search(int a, int b, int c);

void Sol() {
    answers.clear();
    casesMap.clear();
    cin >> A_MAX >> B_MAX >> C_MAX;

    int a = 0;
    int b = 0;
    int c = C_MAX; 

    search(a, b, c);
    sort(answers.begin(), answers.end());
    
    for(int a : answers) {
        cout << a << " ";
    }
    cout << endl;
}

void search(int a, int b, int c) {
    if(a == 0) {
        answers.push_back(c);
    }

    casesMap.insert({{a, b, c}, 1});

    int maxs[3] = {A_MAX, B_MAX, C_MAX};
    int cur[3] = {a, b, c};
    for(int src = 0; src < 3; ++src) {
        for(int dst : Adj[src]) {
            int next[3] = {a, b, c};

            int maxAvailable = maxs[dst] - cur[dst];

            if(maxAvailable >= cur[src]) {
                next[src] = 0;
                next[dst] = cur[dst] + cur[src];
            }
            else {
                next[src] = cur[src] - maxAvailable;
                next[dst] = maxs[dst];
            }

            if(casesMap.find({next[0], next[1], next[2]}) == casesMap.end()) {
                search(next[0], next[1], next[2]);
            }
             
        }
    }
}

