/*
HappyBirthday to me
https://school.programmers.co.kr/learn/courses/30/lessons/118669
*/
#include <string>
#include <vector>
#include <queue>
#define INF (10000001)

using namespace std;

typedef struct edge {
    int dst;
    int weight;
    bool operator>(const edge& other) const {
        return weight > other.weight;
    }
}edge_t;

vector<vector<edge_t>> A;
vector<int> isSummit;
vector<int> isGate;

int answerWeight;
int answerSummit;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    A.assign(n + 1, {});
    isSummit.assign(n + 1, false);
    isGate.assign(n + 1, false);

    for (int s : summits) {
        isSummit[s] = true;
    }

    for (int g : gates) {
        isGate[g] = true;
    }

    //adjacent list
    for (const auto& p : paths) {
        int n1, n2, w;
        n1 = p[0];
        n2 = p[1];
        w = p[2];
        A[n1].emplace_back(edge_t{ n2,w });
        A[n2].emplace_back(edge_t{ n1, w });
    }

    answerWeight = INF;
    answerSummit = -1;

    for (const auto& g : gates) {
        vector<int> dist(n + 1, INF);
        vector<bool> visit(n + 1, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[g] = 0;
        pq.push({ 0, g });

        while (!pq.empty()) {
            pair<int, int> weight_node = pq.top();
            pq.pop();

            int curWeight = weight_node.first;
            int curNode = weight_node.second;

            if (visit[curNode]) { continue; }
            visit[curNode] = true;

            for (const auto& edgeToNext : A[curNode]) {
                int weightToNextNode = edgeToNext.weight;
                int nextNode = edgeToNext.dst;

                if (isGate[nextNode] || visit[nextNode]) {
                    continue;
                }

                dist[nextNode] = max(curWeight, weightToNextNode);

                if (isSummit[nextNode] == false && dist[nextNode] <= answerWeight) {//시간초과 해결법
                    pq.push({ dist[nextNode], nextNode });
                }
                else if(isSummit[nextNode] == true) { 
                    if (answerWeight > dist[nextNode] || (answerWeight == dist[nextNode] && nextNode < answerSummit)) { 
                        answerWeight = dist[nextNode];
                        answerSummit = nextNode;
                    }
                }

            }
        }
    }

    return { answerSummit, answerWeight };
}

