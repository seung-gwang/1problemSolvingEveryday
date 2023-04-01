/*
https://www.acmicpc.net/problem/20055
*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct space {
	int num;
	int dur;
	bool hasRobot;
} space_t;

queue<space_t> up;
queue<space_t> low;

int N, K;
int turn;
int zeroDurCount;

void PutRobot();
void PickRobot();
void ForwardRobots();
void RotateBelt();

void Initialize() {
	while (!up.empty()) {
		up.pop();
	}
	while (!low.empty()) {
		low.pop();
	}
	turn = 0;
	zeroDurCount = 0;
}

void Input() {
	cin >> N >> K;

	stack<int> durs;
	for (int i = 0; i < 2 * N; ++i) {
		int temp;
		cin >> temp;
		durs.push(temp);
	}

	for (int num = 2 * N; num >= N + 1; --num) {
		int dur = durs.top();
		durs.pop();
		low.push({ num, dur, false });
	}

	for (int num = N; num >= 1; --num) {
		int dur = durs.top();
		durs.pop();
		up.push({ num, dur, false });
	}
}

int main() {
	Initialize();
	Input();

	do {
		RotateBelt();
		PickRobot();
		ForwardRobots();
		PickRobot();
		PutRobot();
		turn++;
	} while (zeroDurCount < K);

	cout << turn << '\n';

	return 0;
}

void PutRobot() {
	if (up.back().hasRobot == false && up.back().dur >= 1) {
		up.back().hasRobot = true;
		if (--up.back().dur == 0) {
			zeroDurCount++;
		}
	}
}

void PickRobot() {
	if (up.front().hasRobot == true) {
		up.front().hasRobot = false;
	}
}

void ForwardRobots() {
	space_t popped = up.front();
	up.pop();
	up.push(popped);
	for (int i = 1; i < N; ++i) {
		if (up.front().hasRobot && !up.back().hasRobot && up.back().dur >= 1) {
			up.back().hasRobot = true;
			if (--up.back().dur == 0) {
				zeroDurCount++;
			}
			up.front().hasRobot = false;
		}
		popped = up.front();
		up.pop();
		up.push(popped);
	}
}

void RotateBelt() {
	space_t popped = up.front();
	up.pop();
	low.push(popped);

	popped = low.front();
	low.pop();
	up.push(popped);
}
