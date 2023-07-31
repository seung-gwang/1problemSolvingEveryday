/*
https://school.programmers.co.kr/learn/courses/30/lessons/42884
*/
#include <string>
#include <vector>
#include <algorithm>
#define INF (99999)
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());

    int left = INF;
    int right = -INF;
    for(const auto& r : routes) {
        int rl = r[0];
        int rr = r[1];
        if(right < rl) {
            answer++;
            left = rl;
            right = rr;
        }
        else {
            left = max(left, rl);
            right = min(right, rr);
        }
        
    }
    return answer;
}