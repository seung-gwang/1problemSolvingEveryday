/*
https://school.programmers.co.kr/learn/courses/30/lessons/70129
*/
#include <string>
#include <vector>

using namespace std;

string gs;
int tCnt = 0;
int rmzCnt = 0;


void do_transform() {
    //1의 개수 -> '길이'
    //그 길이를 이진법으로 표현하여 문자열로 저장 :gs
    int oneCnt = 0;
    for(const auto& d : gs) {
        if(d == '1') {
            oneCnt++;
        }
        else {
            rmzCnt++;
        }
    }
    
    string temp = "";
    while(oneCnt > 1) {
        temp = to_string((oneCnt % 2)) + temp;
        oneCnt /= 2;
    }
    
    if(oneCnt == 1) {
        temp = "1" + temp;
    }
    
    gs = temp;
}

vector<int> solution(string s) {
    gs = s;
    while(gs != "1") {
        do_transform();
        tCnt++;
    }
    
    return {tCnt, rmzCnt};
}