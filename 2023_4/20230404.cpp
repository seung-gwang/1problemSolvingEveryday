/*
https://www.acmicpc.net/problem/2042
*/
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long sll; // signed long long

using namespace std;

sll N, M, K; //데이터 수 , 변경횟수, 구간합 횟수
vector<sll> segmentTree;
sll offset;

void Solve();
void update(sll b, sll c);
sll getSectionSum(sll b, sll c);

int main() {
    Solve();
    return 0;
}

void Solve() {
    cin >> N >> M >> K;

    sll exponent = 0; 
    sll product = 1;

    while(product < N) {
        exponent++;
        product *= 2; 
    }
    //product : 2 ^ (k)
    offset = product;
    sll treeSize = product * 2;
    segmentTree.resize(treeSize);
    fill(segmentTree.begin(), segmentTree.end(), 0);

    for(sll i = 0; i < N; ++i) {
        cin >> segmentTree[i + product];
    }

    for(sll idx = product - 1; idx > 0; --idx) {
        segmentTree[idx] = segmentTree[2 * idx] + segmentTree[2 * idx + 1];
    }


    for(sll j = 0; j < M + K; ++j) {
        sll a, b, c;
        cin >> a >> b >> c;

        if(a == 1) {
            update(b, c); //b번째 수를 c로 변경
        }
        else if ( a == 2) {
            sll sum = getSectionSum(b, c); //b번째 수부터 c번째 수의 구간 합을 구함
            cout << sum << '\n';
        }
    }
}

void update(sll b, sll c) {
    sll targetIdx = b + offset - 1;
    sll diff = segmentTree[targetIdx] - c;
    
    sll idx = targetIdx;
    while(idx > 0) {
        segmentTree[idx] -= diff;
        idx /= 2;
    }
}

sll getSectionSum(sll b, sll c) {
    sll startIdx = b + offset - 1;
    sll endIdx = c + offset - 1;

    sll ret = 0;
    while(startIdx <= endIdx) {
        if(startIdx % 2 == 1) {
            ret += segmentTree[startIdx];
        }
        startIdx = (startIdx + 1) / 2;

        if(endIdx % 2 == 0) {
            ret += segmentTree[endIdx];
        }
        endIdx = (endIdx - 1) / 2;
    }

    return ret;
}