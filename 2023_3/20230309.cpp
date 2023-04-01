/*
https://www.acmicpc.net/problem/21568
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long GCD(long a, long b);
pair<long, long> Execute(long a, long b);

int main() {
    long A, B, C;
    cin >> A >> B >> C;

    long gcd = GCD(A, B);

    if (C % gcd != 0) {
        cout << "-1" << endl;
    }
    else {
        const int K = C / gcd;
        pair<long, long> ans = Execute(A / gcd, B/ gcd);


        cout << ans.first * K << ' ' << ans.second * K << '\n';

    }
    
    return 0;
}

pair<long, long> Execute(long a, long b) {
    pair<long, long> xy;

    
    if(b == 0) {
        xy.first = 1;
        xy.second = 0;
        return xy;
    }

    long q = a / b;
    pair<long, long> temp = Execute(b, a % b);
    xy.first = temp.second;
    xy.second = temp.first - temp.second * q;
    return xy;
}

long GCD(long a, long b) {
    if(b == 0) {
        return a;
    }

    return GCD(b, a % b);
} 


/* 첫 답안
int GCD(int a, int b);
pair<int, int> ExtendedEucl(int a, int b, int c);
void GetRQ(int a, int b, stack<pair<int, int>>& rqs);
void GetXY(int& px, int& py, stack<pair<int, int>>& rqs);

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int gcd = GCD(A, B);

    if(C % gcd != 0) {
        cout << -1 << '\n';
    }
    else {
        pair<int, int> answer = ExtendedEucl(A, B, C);
        cout << answer.first << ' ' << answer.second << '\n';
    }

    return 0;
}

int GCD(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    
    return GCD(b, a % b);
}

pair<int, int> ExtendedEucl(int a, int b, int c) {
    stack<pair<int, int>> rqs;
    GetRQ(a, b, rqs);

    int x = 1;
    int y = 0;
    GetXY(x, y, rqs);

    const int K = c / GCD(a, b);
    return make_pair(x * K, y * K);
}

void GetRQ(int a, int b, stack<pair<int, int>>& rqs) {
    int r = a % b;
    int q = a / b;

    rqs.push(make_pair(r, q));
    if(r == 0) {
        return;
    }
    else {
        GetRQ(b, r, rqs);
    }
}

void GetXY(int& px, int& py, stack<pair<int, int>>& rqs) {
    pair<int, int> answer;
    if(rqs.size() == 0) {
        return;
    }
    else {
        int q = rqs.top().second;
        rqs.pop();
        int temp = px;
        px = py;
        py = temp - py * q;

        GetXY(px, py, rqs);
    }

}
*/