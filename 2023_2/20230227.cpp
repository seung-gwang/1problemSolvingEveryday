/*
https://school.programmers.co.kr/learn/courses/30/lessons/86053?language=cpp
*/
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    long long start = 0;
    /*
    최대시간 : a 와 b가 10^9이고 편도시간은 전부 10^5 수송용량 전부 1
    왕복시간 : 10^5 * 2 -> 금, 은 각각 : (10^9)*(10^5)*2
    */
    long long end = (long long)pow(10,9) * (long long)pow(10,5) * 2 * 2;
    const int CITY_COUNT = w.size();
    
    while(start <= end) {
        long long mid = (start + end) / 2;
        /* 
        mid 시간동안, 광물 총 수송 가능 량 : S
        S < a + b 이면 start = mid + 1 -> 시간이 더 필요함
        S > a + b 이면 mid 시간 동안 (a + b) 만큼의 광물 운송 가능
        
            단, 
                금 수송 가능량 a 이상
                은 수송 가능량 b 이상
            (ex: 금은 하나도 안옮기고 은만 S 만큼 옮기는 경우 -> X)
            이여야 함. -> 불가능하면 시간이 더 필요 (start = mid + 1)
            가능하다면 더 짧은시간에 만족하는 경우를 찾을 수도 있으므로
            답을 mid로 지정 해두고 (end = mid - 1)하여 탐색 진행
            
        */
        long long total = 0;
        long long gold = 0;
        long long silver = 0;
        
        for(int i = 0; i < CITY_COUNT; ++i) {
            long long deliv = 0;
            int time = t[i];
            
            deliv += (mid / (2 * time)) * (long long)w[i]; //mid 시간동안 한 도시에서 수송하는 총 물량
            
            if(mid % (2 * time) >= time) { //편도 한번 더 가능
                deliv += w[i];
            }
                    /*
                    mid 시간 동안 최대로 전달할수 있는 금, 은
                    */
            gold += min(deliv, (long long)g[i]);
            silver += min(deliv, (long long)s[i]);
            total += min(deliv, (long long)g[i] + s[i]); //실제로 운반되는 총량(금 + 은)
            
        }
        
        /*
        mid 시간동안의 금 최대 수송량이 목표량(a)에 미치지 못하면 더 긴 시간이 필요하단 뜻
        은도 마찬가지
        */ 
        if(total < a + b || gold < a || silver < b) {
            start = mid + 1;
        }
        else {
            answer = mid;
            end = mid - 1;
        }
        
    }
    
    return answer;
}