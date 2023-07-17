/*
https://school.programmers.co.kr/learn/courses/30/lessons/12939
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string temp = "";
    vector<int> integers;
    for(const auto& c : s) {
        if(c == ' ') {
            integers.push_back(stoi(temp));
            temp = "";
        }
        else {
            temp += c;
        }
    }
    integers.push_back(stoi(temp));
    
    sort(integers.begin(), integers.end());
    int mmax = integers.back();
    int mmin = integers.front();
    
    answer = to_string(mmin) + " " + to_string(mmax);
    return answer;
}