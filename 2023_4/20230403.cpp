/*
https://school.programmers.co.kr/learn/courses/30/lessons/172927
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int PickMinerals(const vector<int>& mineralGroup, int pickType) {
    const int fatigues[3][3] = {
        {1,1,1},
        {5,1,1},
        {25,5,1}
    };

    int ret = 0;
    for (int mineralType = 0; mineralType < 3; ++mineralType) {
        for (int count = 0; count < mineralGroup[mineralType]; ++count) {
            ret += fatigues[pickType][mineralType];
        }
    }

    return ret;
}

int GetPick(vector<int>& currentPicks) {
    for (int i = 0; i < 3; ++i) {
        if (currentPicks[i] > 0) {
            --currentPicks[i];
            return i;
        }
    }

    return -1;
}


int solution(vector<int> picks, vector<string> minerals) {
    vector<string> mineralsCpy = minerals;
    vector<vector<int>> group5MineralCounts;

    const int totalPickCount = picks[0] + picks[1] + picks[2];
    const int maxMineralCount = 5 * totalPickCount;
    int delCount = minerals.size() - maxMineralCount;

    if (delCount > 0) {
        for (int i = 0; i < delCount; ++i) {
            if (mineralsCpy.size() > 0) {
                mineralsCpy.erase(mineralsCpy.end() - 1);
            }
        }
    }
    

    int groupCount = mineralsCpy.size() / 5;
    int remainder = mineralsCpy.size() % 5;
    if (remainder > 0) { groupCount++; }

    for (int i = 0; i < groupCount; ++i) {
        vector<int> dia_iron_rock(3, 0);
        for (int j = 0; j < 5; ++j) {
            string m = mineralsCpy.front();
            mineralsCpy.erase(mineralsCpy.begin());
            if (m == "diamond") {
                dia_iron_rock[0]++;
            }
            else if (m == "iron") {
                dia_iron_rock[1]++;
            }
            else {
                dia_iron_rock[2]++;
            }

            if (mineralsCpy.size() == 0) { break; }

        }
        group5MineralCounts.push_back(dia_iron_rock);
    }

    sort(group5MineralCounts.begin(), group5MineralCounts.end(), greater<>());

    vector<int> possiblePicks = picks;

    int fatigueSum = 0;
    for (vector<int>& mineralGroup : group5MineralCounts) {
        int bestPickPossible = GetPick(possiblePicks);

        if (bestPickPossible == -1) { // 사용 가능한 곡괭이가 없다면 -1 반환
            break;
        }

        fatigueSum += PickMinerals(mineralGroup, bestPickPossible);
    }

    return fatigueSum;
}
