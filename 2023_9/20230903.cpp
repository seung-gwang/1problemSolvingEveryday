//삼성 SDS 기지국 문제 1
import java.util.Scanner;
public class Telecom {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int testCnt = sc.nextInt();

        for(int t = 0; t < testCnt; ++t) {
            int n = sc.nextInt();
            int hCnt = 0;
            char map[][] = new char[n][n];
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    map[i][j] = sc.next().charAt(0);
                    if(map[i][j] == 'H') {hCnt++;}
                }
            }

            for(int cy = 0; cy < n; ++cy) {
                for(int cx = 0; cx < n; ++cx) {
                    int curChar = map[cy][cx];
                    if(curChar == 'A' || curChar == 'B' || curChar == 'C') {
                        int dy[] = {-1,1,0,0}; //Up, down, left, right
                        int dx[] = {0,0,-1,1};
                        for(int dir = 0; dir < 4; ++dir) {
                            for(char dist = 1; dist <= curChar - 'A' + 1; ++dist) {
                                int ny = cy + dy[dir]*dist;
                                int nx = cx + dx[dir]*dist;
                                if(ny < 0 || ny >= n || nx < 0 || nx >= n) {continue;}
                                if(map[ny][nx] == 'H') {
                                    map[ny][nx] = 'X';
                                    hCnt--;
                                }
                            }
                        }
                    }
                }
            }
            System.out.printf("#%d %d\n", t+1, hCnt);
        }
        sc.close();

    }
}
