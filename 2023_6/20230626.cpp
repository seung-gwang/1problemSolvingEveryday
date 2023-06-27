/*
https://school.programmers.co.kr/tryouts/83555/challenges
'소수 찾기'
*/

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

typedef unsigned long long ull;
using namespace std;

int LEN;
void DFS(int curIdx, string numstr);
vector<string> combis;
unordered_map<ull, bool> um;
string g_numbers;

bool isPrime(const ull num) {
    if (num <= 1) {
        return false;
    }

    for (ull i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int solution(string numbers) {
    sort(numbers.begin(), numbers.end());
    combis.clear();
    g_numbers = numbers;
    LEN = numbers.length();
    DFS(0, "");

    um.clear();
    for (const auto& combi : combis) {
        string combiCpy = combi;
        do {
            ull num = stoi(combiCpy);
            if (isPrime(num) && um.find(num) == um.end()) {
                um.insert({ num, true });
            }
        } while (next_permutation(combiCpy.begin(), combiCpy.end()));
    }

    return um.size();
}



void DFS(int curIdx, string numstr) {
    if (curIdx > LEN - 1) {
        if (numstr.length() > 0) {
            combis.push_back(numstr);
        }
        
        return;
    }

    DFS(curIdx + 1, numstr);
    DFS(curIdx + 1, numstr + g_numbers[curIdx]);
    return;
}