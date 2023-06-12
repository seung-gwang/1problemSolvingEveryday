/*
https://school.programmers.co.kr/tryouts/83562/challenges#
'큰 수 만들기'
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> q;
    int K = k;
    
    q.push_back(number[0]);
    
    for(int i = 1; i < number.size(); ++i) {
        char n = number[i];
        
        while(!q.empty() && q.back() < n && K > 0) {
            K--;
            q.erase(q.end() - 1);
        }
        q.push_back(n);
    }
    
    for(int i = 0; i < number.size() - k; ++i) {
        answer += q[i];
    }
    
    return answer;
}