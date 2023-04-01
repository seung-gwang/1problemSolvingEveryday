/*
https://www.acmicpc.net/problem/3108
*/
#include <iostream>
#include <vector>

typedef struct square {
    int x1;
    int y1;
    int x2;
    int y2;
    unsigned int sqNum;
}sq_t;

using namespace std;

static vector<sq_t> squares;
static vector<vector<int>> connection;
static vector<bool> visit;

bool haveIntersetion(const sq_t* s1, const sq_t* s2);
void DFS(const int node);

int sol() {
    int N;
    cin >> N;

    squares.resize(N);
    connection.resize(N);

    for (vector<int>& c : connection) {
        c.clear();
    }


    int hasOrigin = 0;
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        //사각형 네 변 중 하나가 원점을 지남
        if (((x1 * x2 <= 0 && (y1 == 0 || y2 == 0))) || ((y1 * y2 <= 0) && (x1 == 0 || x2 == 0))) {
            hasOrigin = 1;
        }
        squares[i] = sq_t{ x1, y1, x2, y2, (unsigned int)i};
    }

    for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
            if (j == k) {
                continue;
            }

            if (haveIntersetion(&squares[j], &squares[k])) {
                connection[j].push_back(k);
            }
        }
       
    }

    visit.resize(N);
    fill(visit.begin(), visit.end(), false);

    int count = 0;
    for (int n = 0; n < N; ++n) {
        if (visit[n] == false) {
            count++;
            visit[n] = true;
            for (int node : connection[n]) {
                DFS(node);
            }
        }
    }


    cout << count - hasOrigin << '\n';


    return 0;
}

bool haveIntersetion(const sq_t* a, const sq_t* b) {

    /*
    1------2
    |      |
    |      |
    0------3 
    */
    
    const int count = 4;
    //0 1 2 3 0
    pair<int, int> aPoints[] = { {a->x1, a->y1}, {a->x1, a->y2}, {a->x2, a->y2}, {a->x2, a->y1}, {a->x1, a->y1} };
    pair<int, int> bPoints[] = { {b->x1, b->y1}, {b->x1, b->y2}, {b->x2, b->y2}, {b->x2, b->y1}, {b->x1, b->y1} };

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            pair<int, int> lineAstart = aPoints[i];
            pair<int, int> lineAend = aPoints[i+1];
            pair<int, int> lineBstart = bPoints[j];
            pair<int, int> lineBend = bPoints[j+1];

            /*
            lineA :vertical
            lineB : horizontal
            */
            if (lineAstart.first == lineAend.first && lineBstart.second == lineBend.second) {
                int bLeftX = min(lineBstart.first, lineBend.first);
                int bRightX = max(lineBstart.first, lineBend.first);

                int aDownY = min(lineAstart.second, lineAend.second);
                int aUpY = max(lineAstart.second, lineAend.second);
                
                if ((bLeftX <= lineAstart.first && lineAstart.first <= bRightX) && (aDownY <= lineBstart.second && lineBstart.second <= aUpY)) {
                    return true;
                }
            }


            /*
            lineA :horizontal
            lineB : vertical
            */
            if (lineBstart.first == lineBend.first && lineAstart.second == lineAend.second) {
                int aLeftX = min(lineAstart.first, lineAend.first);
                int aRightX = max(lineAstart.first, lineAend.first);

                int bDownY = min(lineBstart.second, lineBend.second);
                int bUpY = max(lineBstart.second, lineBend.second);

                if ((aLeftX <= lineBstart.first && lineBstart.first <= aRightX) && (bDownY <= lineAstart.second && lineAstart.second <= bUpY)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void DFS(const int node) {
    visit[node] = true;
    for (int n : connection[node]) {
        if (visit[n] == false) {
            visit[n] = true;
            DFS(n);
        }
    }
}

int main() {
    sol();
    return 0;
}