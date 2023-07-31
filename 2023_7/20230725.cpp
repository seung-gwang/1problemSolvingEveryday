/*
https://school.programmers.co.kr/learn/courses/30/lessons/135808
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.rbegin(), score.rend());
    const int N = score.size();
    for(int i = m-1; i < N; i+=m) {
        answer += (m * score[i]);
    }
    
    return answer;
}