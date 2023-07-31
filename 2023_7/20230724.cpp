/*
https://school.programmers.co.kr/learn/courses/30/lessons/82612
*/
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long sum = 0;
    for(int i = 1; i <= count; ++i) {
        sum += price * i;
    }
    
    answer = sum - money > 0 ? sum - money : 0;
    return answer; 
}