/*
https://school.programmers.co.kr/tryouts/83578/challenges
*/
#include <string>
#include <vector>
#define MAX_TIME (1000000000000000000)
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long l = 0;
    long long r = MAX_TIME;
    
    while(l <= r) {
        long long mid = (l + r) / 2;
        long long count = 0;
        for(const auto& t : times) {
            count += (mid / (long long)t);
        }
        
        if(count >= n) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    
    return answer;
}