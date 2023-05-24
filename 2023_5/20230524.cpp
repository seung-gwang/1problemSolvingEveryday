/*
https://school.programmers.co.kr/tryouts/83539/challenges
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*solution memo
ex1)
headgear :  2
eyewear : 1
-> (2 + 1) * (1 + 1) - 1 = 5
ex2)
face : 3
-> (3 + 1) - 1 = 3
*/

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> um;
    
    int combi = 1;
    for(const auto& c : clothes) {
        if(um.find(c[1]) != um.end()) {
            combi /= (um[c[1]] + 1);
            um[c[1]]++;
            combi *= (um[c[1]] + 1);
        }
        else {
            um.insert({c[1], 1});
            combi *= 2;
        }
    }
    
    return combi - 1;
}