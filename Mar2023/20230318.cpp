/*
https://www.acmicpc.net/problem/2885
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	int k;
	cin >> k;
	int size = k;

	queue<int> bitQ;
	int bit1Count = 0;
	int bit0Count = 0;

	while (size != 0) {
		int bit = size % 2;

		if (bit == 1) {
			bit1Count++;
		}
		else {
			bit0Count++;
		}

		bitQ.push(bit);
		size /= 2;	
	}

	if (bit1Count == 1) {
		cout << (int)pow(2, bitQ.size() - 1) << ' ' << 0 << '\n';
		return 0;
	}

	int chocoSize = (int)pow(2, bitQ.size());

	cout << chocoSize << ' ';

	int popCount = 0;
	while (true) {
		int bit = bitQ.front();
		bitQ.pop();
		popCount++;

		if (bit == 1) {
			break;
		}
	}

	int smallest = (int)pow(2, popCount - 1);
	int cutCount = 0;

	while (chocoSize > smallest) {
		chocoSize /= 2;
		cutCount++;
	}

	cout << cutCount << '\n';
}