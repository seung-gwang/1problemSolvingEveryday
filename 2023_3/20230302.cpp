/*
https://www.acmicpc.net/problem/1459
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long GoStraigntAndDiagonal(unsigned long long x, unsigned long long y, unsigned long long w, unsigned long long s);


int sol() {
	unsigned long long answer;
	unsigned long long x ,y ,w, s;
	cin >> x >> y >> w >> s;

	if (2 * w < s) {
		answer = (x + y) * w;
	}
	else {
		unsigned long long m = min(x, y);
		unsigned long long M = max(x, y);

		if (M == 0) {
			answer = 0;
		}
		else {
			unsigned long long temp0 = GoStraigntAndDiagonal(x, y, w, s);

			unsigned long long temp1, temp2, temp3;
			unsigned long long useW; 
			
			useW = M % 2 == m % 2 ? 0 : 1;
			temp1 = M * s + w * useW;

			useW = (M - 1) % 2 == m % 2 ? 0 : 1;
			temp2 = (M - 1) * s + w * useW + w;

			useW = (M + 1) % 2 == m % 2 ? 0 : 1;
			temp3 = (M - 1) * s + w * useW + w;


			answer = min(temp0, temp1);
			answer = min(answer, temp2);
			answer = min(answer, temp3);
		}
		
	}
	
	cout << answer << '\n';

	return 0;
}

unsigned long long GoStraigntAndDiagonal(unsigned long long x, unsigned long long y, unsigned long long w, unsigned long long s) {
	unsigned long long m = min(x, y);
	unsigned long long r = max(x, y) - m;
	return m * s + w * r;
}


int main() {
	sol();
	return 0;
}