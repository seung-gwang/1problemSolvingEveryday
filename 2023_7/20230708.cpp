/*
https://school.programmers.co.kr/learn/courses/30/lessons/131701
*/
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int N = elements.size();
    set<int> sums;

    int totalSum = 0;
    for (const auto& e : elements) {
        sums.insert(e);
        totalSum += e;
    }


    sums.insert(totalSum);
    for (int i = 0; i < N; ++i) {
        int remove = 0;
        int sum = elements[i];
        for (int j = i+1; j < N; ++j) {
            remove += elements[j];
            sum += elements[j];
            sums.insert(totalSum - remove);
            sums.insert(sum);
        }
        
    }



    return sums.size();
}

