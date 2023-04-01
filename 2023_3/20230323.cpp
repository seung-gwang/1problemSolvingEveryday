/*
https://www.acmicpc.net/problem/23291
*/
#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>
#include <limits.h>
using namespace std;

/*
N개 어항, 각각 한마리 이상의 물고기

어항정리
	1.가장 물고기가 적은 어항 -> 물고기 한마리 넣기, 최소 물고기인 어항 여러개면, 각각에 하나씩 넣기
	2. 어항 쌓기
	3. 2개 이상 쌓인 어항 -> 시계 방향 90도 돌림, 그러고 다시 쌓음.
		높이 <= 오른쪽에 1개만 쌓인 어항들 수... 이면 계속 반복
	4. 인접한 어항 -> 차이, 차이 // 5 = d, d > 0 이면, 많은쪽에서 적은쪽으로 d마리 이동 //동시업데이트 필요
	5. 왼쪽에서 오른쪽으로, 아래에서 위로 -> 순서로 ...일렬로 재배치
	6.가운데 중심 왼쪽 N/2개를 들어서 시계방향 180도 돌리고 오른쪽 N/2개 위에 올려넣기 -> 2회 반복
	7. 다시 일렬로 재배열 (왼쪽에서 오른쪽, 아래에서 위 순서)
	8.가장 많은 물고기 어항 - 가장 적은 물고기 어항 물고기 수 <= K 일때까지 반복... 몇번 반복했는지 출력
*/

int N, K;
vector<vector<int>> tanks;
void ControlFishNum();
void Input() {
	cin >> N >> K;
	tanks.clear();

	for (int i = 0; i < N; ++i) {
		int fishCount;
		cin >> fishCount;
		tanks.push_back({ fishCount });
	}
}

int Organize() {
	

	//1.가장 물고기가 적은 어항->물고기 한마리 넣기, 최소 물고기인 어항 여러개면, 각각에 하나씩 넣기
	vector<int> minFishCountIdxs;
	int minFishCount = INT_MAX;
	for (int i = 0; i < N; ++i) {
		int fishCount = tanks[i].front();

		if (fishCount < minFishCount) {
			minFishCountIdxs.clear();
			minFishCount = fishCount;
		}

		if (fishCount == minFishCount) {
			minFishCountIdxs.push_back(i);
		}
	}

	for (int idx : minFishCountIdxs) {
		tanks[idx][0]++;
	}

	//2. 어항 쌓기 N : 4, 8, 12, 16 ...
	int width = 1;
	int height = 1;
	int stackCount = 0;

	vector<pair<int, int>> widthHeights;
	//N = 12;
	while (width * height <= N) {
		widthHeights.push_back({ width, height });
		if (width == height) {
			height++;
		}
		else {
			width++;
		}
		stackCount++;
	}
	stackCount--;
	widthHeights.erase(widthHeights.end() - 1);


	for (pair<int, int> wh : widthHeights) {
		int W = wh.first;
		int H = wh.second; //이걸 들어서 공중부양해서 90도 돌리고 오른쪽에 붙임


		stack<vector<int>> fishCountStack;

		//앞줄부터 스택에 넣고 다시 빼면서 순서대로 깔면 90도 회전 효과
		for (int w = 0; w < W; ++w) {
			fishCountStack.push(tanks.front());
			tanks.erase(tanks.begin());
		}

		while (!fishCountStack.empty()) {
			vector<int> vertical = fishCountStack.top();
			fishCountStack.pop();

			for (int h = 0; h < H; ++h) {
				tanks[h].push_back(vertical[h]);
			}
		}
	}
	
	/*
	인접 어항 확인 : 차이값 diff
	diff // 5 = d, d > 0이면 많은쪽에서 적은쪽으로 d마리 이동
	*/

	//물고기 조절 작업
	ControlFishNum();
	

	int nTemp = N;
	for (int clockWise = 0; clockWise < 2; ++clockWise) {
		stack<vector<int>> fishStack;
		for (int i = 0; i < nTemp / 2; ++i) {
			fishStack.push(tanks.front());
			tanks.erase(tanks.begin());
		}

		for (int j = 0; j < nTemp / 2; ++j) {
			for (auto it = fishStack.top().rbegin(); it != fishStack.top().rend(); ++it) {
				tanks[j].push_back(*it);
			}
			
			fishStack.pop();
		}

		nTemp /= 2;
	}
	
	ControlFishNum();

	int maxVal = 0;
	int minVal = INT_MAX;
	for (vector<int>& f : tanks) {
		maxVal = max(maxVal, f.front());
		minVal = min(minVal, f.front());
	}

	return maxVal - minVal;
}

void ControlFishNum() {
	vector<int> moveVal;
	vector<pair<int*, int*>> movePairs;
	for (int v = 0; v < tanks.size() - 1; ++v) {
		//수평 : 최하단 이동 체크
		int fh1 = tanks[v][0];
		int fh2 = tanks[v + 1][0];

		if (abs(fh1 - fh2) / 5 > 0) {
			moveVal.push_back(abs(fh1 - fh2) / 5);
			int* src = tanks[v][0] > tanks[v + 1][0] ? &tanks[v][0] : &tanks[v + 1][0];
			int* dst = tanks[v][0] < tanks[v + 1][0] ? &tanks[v][0] : &tanks[v + 1][0];
			movePairs.push_back(make_pair(src, dst));
		}

		if (tanks[v + 1].size() > 1) {
			for (int i = 1; i < tanks[v].size(); ++i) {
				int fn1 = tanks[v][i];
				int fn2 = tanks[v + 1][i];

				if (abs(fn1 - fn2) / 5 > 0) {
					moveVal.push_back(abs(fn1 - fn2) / 5);
					int* src = tanks[v][i] > tanks[v + 1][i] ? &tanks[v][i] : &tanks[v + 1][i];
					int* dst = tanks[v][i] < tanks[v + 1][i] ? &tanks[v][i] : &tanks[v + 1][i];
					movePairs.push_back(make_pair(src, dst));
				}
			}
		}
	}
	
	for (int v = 0; v < tanks.size(); ++v) {
		if (tanks[v].size() > 1) { //수직 
			for (int h = 0; h < tanks[v].size() - 1; ++h) {
				int fv1 = tanks[v][h];
				int fv2 = tanks[v][h + 1];

				if (abs(fv1 - fv2) / 5 > 0) {
					moveVal.push_back(abs(fv1 - fv2) / 5);
					int* src = tanks[v][h] > tanks[v][h + 1] ? &tanks[v][h] : &tanks[v][h + 1];
					int* dst = tanks[v][h] < tanks[v][h + 1] ? &tanks[v][h] : &tanks[v][h + 1];
					movePairs.push_back(make_pair(src, dst));
				}

			}
		}
	}

	for (int m = 0; m < movePairs.size(); ++m) {
		int fishCount = moveVal[m];
		int* src = movePairs[m].first;
		int* dst = movePairs[m].second;

		*src -= fishCount;
		*dst += fishCount;
	}


	vector<int> tempFish;
	for (vector<int>& vertical : tanks) {
		for (int f : vertical) {
			tempFish.push_back(f);
		}
	}

	tanks.clear();
	for (int t : tempFish) {
		tanks.push_back({ t });
	}
}

int Sol() {
	Input();

	int count = 0;
	while (true) {
		int diff = Organize();
		count++;

		if (diff <= K) {
			break;
		}
	}

	cout << count << '\n';
	return 0;
}

int main() {
	Sol();
	return 0;
}