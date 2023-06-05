/*
https://school.programmers.co.kr/tryouts/83545/challenges
*/
#include <string>
#include <vector>
#include <queue>
typedef struct truck{
    int pushedTime;
    int weight;
} truck_t;

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int finCount = 0;
    
    queue<int> weightQ;
    queue<truck_t> onBridgeQ;
    
    for(const auto& t : truck_weights) {
        weightQ.push(t);
    }
    
    int curTime = 0;
    int onBridgeWeightSum = 0;
    while(true) {
        while(!onBridgeQ.empty() && onBridgeQ.front().pushedTime + bridge_length <= curTime) {
            onBridgeWeightSum -= onBridgeQ.front().weight;
            onBridgeQ.pop();         
        }
        
        if(!weightQ.empty() && onBridgeWeightSum + weightQ.front() <= weight) {
            onBridgeWeightSum += weightQ.front();
            onBridgeQ.push({curTime ,weightQ.front()});
            weightQ.pop();
        }
        
        curTime++;
        
        if(onBridgeQ.empty() && weightQ.empty()) {
            break;
        }
    }
    
    answer = curTime;
    return answer;
}