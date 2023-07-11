/*
https://school.programmers.co.kr/learn/courses/30/lessons/132265
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> A; //topping number - count
    int diversityA = 0; 
    for(const auto& t : topping) {
        if(A.find(t) == A.end()) {
            A.insert({t, 1});
            diversityA++;
        }
        else {
            A[t]++;
        }
    }
    
    unordered_map<int, int> B;
    int diversityB = 0;
    for(const auto& t : topping) {
        if(--A[t] == 0) {
            diversityA--;
        }
        
        if(B.find(t) == B.end()) {
            B.insert({t, 1});
            diversityB++;    
        }
        else {
            B[t]++;
        }
        
        if(diversityA == diversityB) {
            answer++;
        }
    }
    return answer;
}