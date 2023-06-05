//https://school.programmers.co.kr/tryouts/83554/challenges
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    const int r1[] = {1,2,3,4,5};//5
    const int r2[] = {2,1,2,3,2,4,2,5};//8
    const int r3[] = {3,3,1,1,2,2,4,4,5,5};//10
    
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    
    for(int i = 0; i < answers.size(); ++i) {
        if(answers[i] == r1[i % 5]) {
            p1++;
        }
        
        if(answers[i] == r2[i % 8]) {
            p2++;
        }
        
        if(answers[i] == r3[i % 10]) {
            p3++;
        }
    }
    
    int mmax = max(p1, p2);
    mmax = max(mmax, p3);
    
    if(mmax == p1) {
        answer.push_back(1);
    }
    
    if(mmax == p2) {
        answer.push_back(2);
    }
    
    if(mmax == p3) {
        answer.push_back(3);
    }
    
    return answer;
}