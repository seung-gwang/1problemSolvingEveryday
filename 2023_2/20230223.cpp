/*
https://www.acmicpc.net/problem/1016
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>


using namespace std;


unsigned long long Pow(const unsigned long long base, const int exp) {
    unsigned long long answer = 1;
    for (int i = 0; i < exp; ++i) {
        answer *= base;
    }
    return answer;
}

int main() {
    unsigned long long minimum;
    unsigned long long maximum;

    cin >> minimum >> maximum;
    const int size = maximum - minimum + 1;

    vector<unsigned long long> nums(size, 0);

    for (unsigned long long i = minimum; i <= maximum; i++) {
        nums[i - minimum] = i;
    }

    for (unsigned long long j = 2; j * j <= maximum; ++j) {
        unsigned long long jj = j * j; //jj는 '제곱수'
        unsigned long long mult = 1;
        
        if (mult * jj <= minimum) {
            mult = minimum / jj;
        }

        while (jj * mult <= maximum) {
            if (jj * mult >= minimum) {
                nums[jj * mult - minimum] = -1;
            }
            mult++;
        }

    }

    int count = 0;
    for (unsigned long long val : nums) {
        if (val != -1) {
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}