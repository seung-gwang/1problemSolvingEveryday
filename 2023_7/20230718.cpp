/*
https://school.programmers.co.kr/learn/courses/30/lessons/161988#
*/
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>
#define MAX_LEN (500000)
#define INF (LL_MAX)
using namespace std;
/*
A : 1 -1 1 -1 ...
B : -1 1 -1 1 ...
*/
long long A[MAX_LEN];
long long B[MAX_LEN];

long long solution(vector<int> sequence) {
    long long answer = LLONG_MIN;
    const int N = sequence.size();
    
    A[0] = sequence[0];
    B[0] = -A[0];
    
    long long aMax = A[0];
    long long aMin = A[0];
    
    long long bMax = B[0];
    long long bMin = B[0];
    
    answer = max(aMax, bMax);
    for(int i = 1; i < N; ++i) {
        if(i % 2 == 0) {
            A[i] = sequence[i] + A[i-1];
            B[i] = (-sequence[i]) + B[i-1];
        }
        else {
            A[i] = (-sequence[i]) + A[i - 1];
            B[i] = sequence[i] + B[i-1];
        }
        
        /*인덱스 0부터 i까지의 구간합이 최대인 경우*/
        answer = max(A[i], answer);
        answer = max(B[i], answer); 
        
        /*최소값 갱신*/
        aMin = min(aMin, A[i]);
        bMin = min(bMin, B[i]);
        
        /*최대값, 구간합 최대값 갱신 : A*/
        if(aMax < A[i]) {
            aMax = A[i];
            answer = max(answer, aMax - aMin);
        }
        
        /*최대값, 구간합 최대값 갱신 : B*/
        if(bMax < B[i]) {
            bMax = B[i];
            answer = max(answer, bMax - bMin);
        }
    }
    
    return answer;
}