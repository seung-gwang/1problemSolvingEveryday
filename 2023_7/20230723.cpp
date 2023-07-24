/*
https://school.programmers.co.kr/learn/courses/30/lessons/12914
*/
#include <string>
#include <vector>
#define DIV (1234567)
using namespace std;


long long solution(int n) {
    long long answer = 0;
    long long D[2001];
    
    D[1] = 1; //1칸
    D[2] = 2; //1칸+1칸 or 2칸
    for(int s = 3; s <=n ; ++s) {
        D[s] = (D[s - 1] + D[s - 2]) % DIV;
    }
    
    answer = D[n] % DIV;
    
    return answer;
}