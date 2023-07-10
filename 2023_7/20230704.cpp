/*
https://school.programmers.co.kr/learn/courses/30/lessons/159994
*/
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int i = 0;
    int j = 0;

    for(const auto& g : goal) {
        if(cards1[i] == g) {
            i++;
        }    
        else if(cards2[j] == g) {
            j++;
        }
        else {
            return "No";
        }
    }
    
    return "Yes";
}