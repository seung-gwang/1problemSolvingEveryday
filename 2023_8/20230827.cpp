/*
https://school.programmers.co.kr/learn/courses/30/lessons/42885
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end()); //50 50 70 80
    int l = 0;
    int r = people.size() - 1;
    
    for(int i = r; i >= l; --i) {
        if(people[i] + people[l] <= limit) {
            l++;
            answer++;
        }
        else {
            answer++;
        }
    }
    
    return answer;
}