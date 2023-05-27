/*
https://school.programmers.co.kr/tryouts/83540/challenges
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> song_t; //playCount, songID
typedef pair<int ,string> count_genre;
//typedef pair<int, int> 

struct comp {
    bool operator()(song_t left, song_t right) {
        if(left.first < right.first) {
            return true;
        }
        else if (left.first == right.first) {
            return left.second > right.second;
        }
        return false;
    }
    
};

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<string> genreRemoveDup;
    unordered_map<string, priority_queue<song_t, vector<song_t>, comp>> um;
    unordered_map<string, int> genreCount;
    
    for(int i = 0; i < genres.size(); ++i) {
        if(um.find(genres[i]) == um.end()) {
            genreRemoveDup.push_back(genres[i]);
            
            um.insert({genres[i], {}});
            um[genres[i]].push({plays[i], i});
            genreCount.insert({genres[i], plays[i]});
        }
        else {
            um[genres[i]].push({plays[i], i});
            genreCount[genres[i]] += plays[i];
        }
    }
    
    priority_queue<count_genre> pq;
    for(const auto& kv : genreCount) {
        pq.push({kv.second, kv.first});
    }
    
    while(!pq.empty()) {
        count_genre t = pq.top();
        
        for(int i = 0; i < 2 && um[t.second].empty() == false; ++i) {
            answer.push_back(um[t.second].top().second);
            um[t.second].pop();
        }
        
        pq.pop();
    }
    
    return answer;
}