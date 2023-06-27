/*
https://school.programmers.co.kr/tryouts/83557/challenges?language=cpp
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> idx;
    for(int i = 0; i < dungeons.size(); ++i) {
        idx.push_back(i);
    }
    
    int rep = 0;
    do {
        int piro = k;
        int cnt = 0;
        for(const auto& i : idx) {
            int curReq = dungeons[i][0];
            int curUse = dungeons[i][1];
            
            if(piro >= curReq) {
                piro -= curUse;
                cnt++;
            }
            else {
                break;
            }
        }
        answer = max(answer, cnt);
        
    }while(next_permutation(idx.begin(), idx.end()));
    
    return answer;
    //return answer;
}