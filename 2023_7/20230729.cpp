/*
https://school.programmers.co.kr/learn/courses/30/lessons/12920
*/
#include <string>
#include <vector>
#include <limits.h>
#define INF (999999)
using namespace std;

int solution(int n, vector<int> cores) {
    int answer;
    
    int coreCnt = cores.size();
    if(n <= coreCnt) {
        return n;
    }
    
    /*
    주어진 mid 시간동안 끝낼 수 있는 job의 수
    job을 n개를 할 수 있는 시간 중 최소를 구하여 time으로 정한다.
    time 시각에 마지막 작업이 등록된다.
    */
    int left = 0;
    int right = INF;
    int time = INF;
    while(left <= right) {
        int mid = (left + right) / 2;
        
        int jobCnt = coreCnt;
        for(int t : cores) {
            jobCnt += (mid / t);
        }
        
        if(jobCnt >= n) {
            right = mid - 1;
            time = min(time, mid);
        }
        else { //jobCnt < n
            left = mid + 1; 
        }
    }
    
    /*
    registered count : 등록된 작업 개수
    time의 직전 시각까지 등록된 작업 개수를 구함.
    */
    int regCnt = coreCnt;
    for(int t : cores) {
        regCnt += (time - 1) / t;
    }
    
    int jobCnt = n - regCnt; /*실제로 남은 작업 수*/
    int coreIdx = 0;
    while (true) {/*마지막 작업이 들어갈 코어를 구함.*/
        if(time % cores[coreIdx % coreCnt] == 0) {
            jobCnt--;
        }
        
        if(jobCnt == 0) {
            answer = coreIdx + 1;
            break;
        }
        coreIdx++;
    }
    
    
    return answer;
}