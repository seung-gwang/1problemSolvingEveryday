/*
https://www.acmicpc.net/problem/11047
*/
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> vals;

int main() {
    cin >> N >> K;
    vals.resize(N);
    for(int i = 0; i < N; ++i) {
        cin >> vals[i];
    }

    int sum = 0;
    int money = K;
    for(auto it = vals.rbegin(); it != vals.rend(); ++it) {
        int val = *it;
        if(val > money) {
            continue;
        }

        int count = money / val;
        money = money % val;
        sum += count;
        if(money == 0) break;
    }
    
    cout << sum << '\n';
    return 0;
}



