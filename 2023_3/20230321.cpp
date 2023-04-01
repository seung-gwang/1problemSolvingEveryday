/*
https://school.programmers.co.kr/learn/courses/30/lessons/140107
*/
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    long long x = 0;

    long long ld = d;
    long long lk = k;

    while (x <= d) {
        double yMax = sqrt(ld * ld - x * x);
        long long yCount = (long long)floor(yMax) / lk;
        answer += (yCount + 1);
        x += k;
    }
    return answer;
}