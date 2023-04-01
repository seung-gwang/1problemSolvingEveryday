/*
https://school.programmers.co.kr/learn/courses/30/lessons/92335
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPrime(const unsigned long long num);

int solution(int n, int k) {
    int answer = -1;

    string numStr = "";
    vector<unsigned long long> candis;

    //k진법으로 변경
    while (true) {
        char digit;
        if (n < k && n != 0) {
            digit = n + '0';
            numStr = digit + numStr;
            break;
        }
        else {
            digit = (n % k) + '0';
            numStr = digit + numStr;
            n /= k;
        }
    }

    cout << numStr << endl;
    //numStr 0으로 자르기
    string pStr = "";
    for (char d : numStr) {
        if (d != '0') {
            pStr += d;
        }
        else {
            if (pStr.length() != 0) {
                unsigned long long temp = stoull(pStr);
                candis.push_back(temp);
                pStr = "";
            }
        }
    }

    if ((pStr.length() != 0)) {
        candis.push_back(stoull(pStr));
    }

    int count = 0;
    for (unsigned long long num : candis) {
        if (isPrime(num)) {
            count++;
        }
    }

    answer = count;
    
    return answer;
}

bool isPrime(const unsigned long long num) {
    if (num == 1) {
        return false;
    }

    if (num == 2) {
        return true;
    }

    for (unsigned long long i = 2; i * i < num + 1; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}