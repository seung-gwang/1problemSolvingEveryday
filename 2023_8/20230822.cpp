/*
https://school.programmers.co.kr/learn/courses/30/lessons/42746
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string a, string b) {
    return a + b > b + a;
}
 
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nstr;
    
    for (auto num : numbers) {
        nstr.push_back(to_string(num));
    }
        
    sort(nstr.begin(), nstr.end(), cmp);
    
    if (nstr[0] == "0") {
        return "0";
    }        
    
    for (auto num : nstr) {
        answer += num;
    }
        
    return answer;
}