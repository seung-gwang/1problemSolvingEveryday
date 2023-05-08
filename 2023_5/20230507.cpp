/*
https://www.acmicpc.net/problem/11758
*/
#include <iostream>
#include <vector>
using namespace std;
typedef struct coord {
    int x;
    int y;
}coord_t;

coord_t points[3];

void Solve();
int main() {
    Solve();
    return 0;
}

void Solve() {
    for(int i = 0; i < 3; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    /*
    x1 x2 x3 x1
    y1 y2 y3 y1
    */
    int ccw = (points[0].x * points[1].y + points[1].x * points[2].y + points[2].x * points[0].y)
     - (points[1].x * points[0].y + points[2].x * points[1].y + points[0].x * points[2].y);
    
    if(ccw < 0) {
        cout << "-1" << '\n';
    }
    else if (ccw > 0) {
        cout << "1" << '\n';
    }
    else {
        cout << "0" << '\n';
    }
}