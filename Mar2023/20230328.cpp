/*
https://www.acmicpc.net/problem/16918
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct space {
	int setTime;
	char status; // 빈 칸은 '.'로, 폭탄은 'O'
} space_t;
int R, C, N;
int T; //time
space_t board[200][200];

void Sol();

int main() {
	Sol();
	return 0;
}

void SetBombAtEmptySpace();
void ExplodeBombs();

void PrintBoard() {
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cout << board[r][c].status;
		}
		cout << '\n';
	}
}

void Sol() {
	cin >> R >> C >> N;

	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			char input;
			cin >> input;

			board[r][c] = { 0, input }; // 빈 칸은 '.'로, 폭탄은 'O'
		}
	}

	T = 1;

	while (T < N) {
		
		T++;
		SetBombAtEmptySpace();

		if (T == N) { break; }

		T++;
		ExplodeBombs();

		if (T == N) { break; }
	}

	PrintBoard();
}

void SetBombAtEmptySpace() {
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (board[r][c].status == '.') {
				board[r][c].status = 'O';
				board[r][c].setTime = T;
			}
		}
	}
}
void ExplodeBombs() {
	int t = T - 3;
	int dy[] = { -1, 1, 0, 0 }; //상하좌우
	int dx[] = { 0, 0, -1, 1 }; //상하좌우

	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (board[r][c].setTime == t && board[r][c].status == 'O') {
				board[r][c].status = '.';

				for (int dir = 0; dir < 4; ++dir) {
					int nr = r + dy[dir];
					int nc = c + dx[dir];
					if (nr < 0 || nc < 0 || nr > R - 1 || nc > C - 1 || board[nr][nc].setTime == t) {
						continue;
					}
					board[nr][nc].status = '.';
				}
			}
		}
	}
}