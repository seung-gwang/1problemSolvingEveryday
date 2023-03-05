/*
https://school.programmers.co.kr/learn/courses/30/lessons/160585?language=cpp
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;

    int countO = 0;
    int countX = 0;
    int countDot = 0;

    bool consec3O = false;
    bool consec3X = false;

    //행 검사 + 전체 개수 count
    for (const string& row : board) {
        if (row == "OOO") {
            consec3O = true;
        }

        if (row == "XXX") {
            consec3X = true;
        }

        for (const char& space : row) {
            if (space == 'O') {
                countO++;
            }

            if (space == 'X') {
                countX++;
            }

            if (space == '.') {
                countDot++;
            }
        }
    }

    //열 검사
    for (int col = 0; col < 3; ++col) {
        if (board[0][col] == '.') {
            continue;
        }
        else {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                if (board[0][col] == 'O') { consec3O = true; }
                else if (board[0][col] == 'X') { consec3X = true; };
            }
        }
    }

    //대각 검사
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'O') { consec3O = true; }
        else if (board[0][0] == 'X') { consec3X = true; }
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'O') { consec3O = true; }
        else if (board[0][2] == 'X') { consec3X = true; }
    }

    //O가 선공이니 딱 하나 많거나 같아야 함
    if (countO == countX) {//X가 둔 상황
        if (consec3O == true) {
            answer = 0;
        }
        else {
            answer = 1;
        }
    }
    else if (countO == countX + 1) {//O가 둔 상황
        if (consec3X == true) {
            answer = 0;
        }
        else {
            answer = 1;
        }
    }
    else {
        answer = 0;
    }


    return answer;
}