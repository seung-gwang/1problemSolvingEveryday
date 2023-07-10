/*
https://school.programmers.co.kr/learn/courses/30/lessons/131127
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int N = discount.size();
    unordered_map<string, int> wantMap;
    
    int targetCnt = 0;
    for(int i = 0; i < want.size(); ++i) {
        wantMap[want[i]] = number[i];
        targetCnt += number[i];
    }
    
    for(int i = 0; i < N; ++i) { //시작일
        unordered_map<string, int> wantMapCpy = wantMap;
        int cnt = 0;
        for(int j = 0; j < 10; ++j) {
            if(i + j >= N) {continue;}
            
            string item = discount[i + j];
            if(wantMapCpy[item] > 0) {
                wantMapCpy[item]--;
                cnt++;
            }
            
        }
        
        if(cnt == targetCnt) {
            answer++;
        }
    }
        
    
    return answer;
}