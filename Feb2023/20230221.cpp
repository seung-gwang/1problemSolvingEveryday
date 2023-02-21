#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    //시간 범위
    long long start = 0;
    long long end = (long long)times[0] * n;

    while (start <= end) {
        long long mid = (start + end) / 2; //총 시간

        long long sum = 0;
        for (int time : times) {
            long long longTime = time;
            sum += (mid / longTime);
        }

        if (sum < n) { //처리 인원이 목표기준보다 적음 -> 더 긴 시간 필요
            start = mid + 1;
        }
        else { //처리 인원이 목표 기준 이상 -> 답이 될수도 있고 더 짧은시간이 가능할수도 있음
            end = mid - 1;
            answer = mid;
        }
    }

    return answer;
}