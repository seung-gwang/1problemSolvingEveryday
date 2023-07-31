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

    /*
    [left, right] : 감시카메라 설치 구역
    */
    int left = INF;
    int right = -INF;
    for(const auto& r : routes) {
        int rl = r[0];
        int rr = r[1];
        /*
            [left, right]와 겹치지 못하는 구역이면 새로 감시 카메라 설치
        */
        if(right < rl) {
            answer++;
            left = rl;
            right = rr;
        }
        else {
        /*
	[left, right]와 겹칠수 있는 구역이면 left, right 범위를 겹치는 구간으로 갱신
        */
            left = max(left, rl);
            right = min(right, rr);
        }
        
    }
    return answer;
}