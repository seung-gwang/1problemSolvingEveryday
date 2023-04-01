/*
https://www.acmicpc.net/problem/5585
*/

#include <iostream>
#include <vector>
using namespace std;


vector<int> coins = { 500, 100, 50, 10, 5, 1 };

int main() {
	int n;
	cin >> n;

	int change = 1000 - n;

	int count = 0;
	for (int val : coins) {
		count += change / val;
		change %= val;

		if (change == 0) {
			break;
		}
	}

	cout << count << '\n';

}