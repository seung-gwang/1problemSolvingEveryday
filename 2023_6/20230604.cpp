/*
https://school.programmers.co.kr/tryouts/83571/challenges
*/
#include <string>
#include <vector>

using namespace std;

vector<int> gnum;
int gtarget;
int ganswer = 0;

void DFS(int numIdx, int cur) {
    if(numIdx == gnum.size()) {
        if(cur == gtarget) {
            ganswer++;
            
        }
        return;
    }
    
    cur += gnum[numIdx];
    DFS(numIdx + 1, cur);
    cur -= gnum[numIdx];
    
    cur -= gnum[numIdx];
    DFS(numIdx + 1, cur);
    cur += gnum[numIdx];
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    gnum.clear();
    for(const auto& n : numbers) {
        gnum.push_back(n);
    }
    gtarget = target;
    
    ganswer = 0;
    DFS(0,0);
    
    return ganswer;
}