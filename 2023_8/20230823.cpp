/*
https://school.programmers.co.kr/learn/courses/30/lessons/42839
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool is_prime(const int n) {
    if(n <= 1) {
        return false;
    }
    
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int solution(string numbers) {
    set<int> primes;
    
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    do {
        string nstr = "";
        for(const auto& i : numbers) {
            nstr += i;
            int p = stoi(nstr);
            if(is_prime(p)) {
                primes.insert(p);
            }
        }
    } while(next_permutation(numbers.begin(), numbers.end()));

    return primes.size();
}