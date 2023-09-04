/*
https://school.programmers.co.kr/learn/courses/30/lessons/42747
*/
#include <string>
#include <vector>
#include <algorithm>
​
using namespace std;
/*
0 1 2 3 4
6 5 3 1 0
*/
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.rbegin(), citations.rend());  
    
    if(citations[0] == 0) {
        return 0;
    }
    
    const int N = citations.size();
    for(int i = 0; i < N; ++i) {
        if(citations[i] > i) {
            answer = i;
        }
        
    }
    
    answer+=1;
    return answer;
}