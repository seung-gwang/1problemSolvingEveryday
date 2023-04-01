/*
https://www.acmicpc.net/problem/14503
*/
#include <iostream>

using namespace std;
#define UP (0)
#define RIGHT (1)
#define DOWN (2)
#define LEFT (3)

#define INVALID_POS (-1)
#define CLEANED (-2)

int board[50][50];
int dir;
int cy, cx;
int N, M;

int numClean;

void RotateCounterClock90() {
	dir = dir == UP ? LEFT : dir - 1;
}

bool MoveBackOrFin() {
	//0 1 2 3
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, -1, 0, 1 };

	int ny = cy + dy[dir];
	int nx = cx + dx[dir];

	if (board[ny][nx] == 1 || ny < 0 || nx < 0 || ny > N - 1 || nx > M - 1 || board[ny][nx] == INVALID_POS) { // 벽 or 무효좌표
		return false;
	}
	else {
		cy = ny;
		cx = nx;
		return true;
	}

}

void MoveForward() { 
	int dy[] = { -1, 0, 1, 0 };
	int dx[] = { 0, 1, 0, -1 }; //up right down left

	int ny = cy + dy[dir];
	int nx = cx + dx[dir];

	cy = ny;
	cx = nx;
}

bool IsFrontUncleanedAndValidPos() {
	int dy[] = { -1, 0, 1, 0 };
	int dx[] = { 0, 1, 0, -1 };

	int ny = cy + dy[dir];
	int nx = cx + dx[dir];

	if (ny < 0 || nx < 0 || ny > N - 1 || nx > M - 1 || board[ny][nx] == CLEANED || board[ny][nx] == 1) {
		return false;
	}

	return true;
}

int sol() {
	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 50; ++j) {
			board[i][j] = INVALID_POS;
		}
	}

	cin >> N >> M;
	cin >> cy >> cx >> dir;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> board[r][c];
		}
	}


	numClean = 0;
	while (true) {

		//현 위치가 청소되지 않았다면 청소한다.
		if (board[cy][cx] == 0) {
			board[cy][cx] = CLEANED;
			numClean++;
		}

		//주변 네 칸을 본다, 주변 네 칸중에 청소 안한곳이 있는지 확인한다.
		bool haveUncleaned = false;
		for (int rot = 0; rot < 4; ++rot) {
			RotateCounterClock90();
			if (IsFrontUncleanedAndValidPos()) {
				haveUncleaned = true;
			}
		}

		//인접 네칸중에 청소한 곳이 있으면
		if (haveUncleaned) {
			RotateCounterClock90();//반시계 방향으로 90도 회전하고
			if (IsFrontUncleanedAndValidPos()) { //앞칸이 청소되지 않은 유효한 칸이라면
				MoveForward(); //한칸 앞으로 전진함.
			}
		}
		else {//없으면 뒤로 가거나 뒤로 갈 칸이 없으면 끝냄.
			if (MoveBackOrFin() == false) {
				goto PRINT;
			}
		}
		
	}

PRINT:
	cout << numClean << endl;

	return 0;
}

int main() {
	sol();
	return 0;
}