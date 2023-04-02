/*
https://school.programmers.co.kr/learn/courses/30/lessons/60059
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void RotateKeyClockwise(vector<vector<int>>& key) {
    int M = key.size();
    vector<vector<int>> keyCpy = key;

    int colPos = M - 1;
    for (int i = M - 1; i >= 0; --i) {
        vector<int> row = keyCpy.front();
        keyCpy.erase(keyCpy.begin());

        for (int r = 0; r < M; ++r) {
            key[r][colPos] = row[r];
        }
        colPos--;
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size();
    int N = lock.size();
    int K = (M * 2) + N - 2;
    bool answer = false;

    vector<vector<int>> extendedLock(K);
    for (int i = 0; i < K; ++i) {
        extendedLock[i].resize(K);
    }

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            extendedLock[i][j] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            extendedLock[i + M - 1][j + M - 1] = lock[i][j];
        }
    }


    for (int r = 0; r < 4; ++r) {//rotate 4회 회전
        RotateKeyClockwise(key);
        for (int i = 0; i < M + N - 1; ++i) {
            for (int j = 0; j < M + N - 1; ++j) {
                //왼쪽 위 좌표 지정

                for (int keyY = 0; keyY < M; ++keyY) {
                    for (int keyX = 0; keyX < M; ++keyX) {
                        extendedLock[i + keyY][j + keyX] += key[keyY][keyX];
                    }
                }

                bool isValidKey = true;
                for (int lockY = M - 1; lockY < M + N - 1; ++lockY) {
                    for (int lockX = M - 1; lockX < M + N - 1; ++lockX) {
                        if (extendedLock[lockY][lockX] != 1) {
                            isValidKey = false;
                            goto KEY_VALIDATION_DONE;
                        }
                    }
                }

            KEY_VALIDATION_DONE:

                if (isValidKey) {
                    answer = true;
                    goto RETURN_ANSWER;
                }

                for (int keyY = 0; keyY < M; ++keyY) {
                    for (int keyX = 0; keyX < M; ++keyX) {
                        extendedLock[i + keyY][j + keyX] -= key[keyY][keyX];
                    }
                }

            }
        }

    }

RETURN_ANSWER:
    return answer;
}
