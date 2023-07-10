/*
https://school.programmers.co.kr/learn/courses/30/lessons/155651
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<vector<int>> bi; //book integer
    for(const auto& b : book_time) {
        int start = 0;
        string temp = b[0].substr(0, 2);
        start += stoi(temp) * 60;
        temp = b[0].substr(3);
        start += stoi(temp);
        
        int end = 0;
        temp = b[1].substr(0, 2);
        end += stoi(temp) * 60;
        temp = b[1].substr(3);
        end += stoi(temp);
        end += 10; //청소시간
        
        bi.push_back({start, end});
    }
    
    vector<vector<int>> rooms;
    sort(bi.begin(), bi.end());
    for(const auto& se : bi) {
        int startTime = se[0];
        int endTime = se[1];
        
        bool isAllocated = false;
        for(auto& r : rooms) {
            if(r[1] <= startTime) {
                r[0] = startTime;
                r[1] = endTime;
                isAllocated = true;
                break;
            }
        }
        
        if(!isAllocated) {
            rooms.push_back({startTime, endTime});
        }
    }
    
    return rooms.size();
}