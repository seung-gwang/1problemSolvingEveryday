/*
https://www.acmicpc.net/problem/1456
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> check;

inline uint64_t getSqrt(const uint64_t N) {
    uint64_t n = 1;
    while(n * n < N) {
        n++;
    }
    return n;
} 

int main() {
    uint64_t A, B;
    cin >> A >> B;

    uint64_t rB = getSqrt(B);
    uint16_t rrB = getSqrt(rB);

    check.resize(rB + 1, false); 
    check[0] = true;
    check[1] = true; 

    for (uint64_t i = 2; i <= rrB; ++i) {
        if (check[i] == true) {
            continue;
        }
        else {
            uint64_t mult = 2;
            while (i * mult <= rB) {
                check[i * mult++] = true;
            }
        }
    }

    uint64_t count = 0;
    for (uint64_t j = 2; j <= rB; ++j) {
        if (check[j] == false) {
            uint64_t almostPrime = j * j;
            while (almostPrime <= B) {
                if (A <= almostPrime) {
                    count++;
                }
                if(almostPrime < UINT64_MAX / j) {
                    almostPrime *= j;
                }
                else {
                    break;
                }
                
            }
        }
    }

    cout << count << '\n';

    return 0;
}