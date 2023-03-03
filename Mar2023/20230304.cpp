/*
https://www.acmicpc.net/problem/1398
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
typedef unsigned long long ull;

using namespace std;

void sol();

int main() {
	sol();
	return 0;
}

unsigned long long Pow(unsigned long long base, unsigned long long exp) {
	unsigned long long ret = 1;
	for (unsigned long long i = 0; i < exp; ++i) {
		ret *= base;
	}
	return ret;
}

void sol() {
	vector<unsigned long long> coins;
	unsigned long long T;
	cin >> T;

	const unsigned long long MAX_PRICE = (unsigned long long)Pow(10, 15);

	unsigned long long k = 0;

	map<ull, ull> coin_count;

	while (true) {
		unsigned long long val = Pow(10, k);
		if (val <= MAX_PRICE) {
			coins.push_back(val);
			coin_count.insert({ val, 0 });
		}
		else {
			break;
		}
		k++;
	}

	k = 0;
	while (true) {
		unsigned long long val = 25 * Pow(100, k);
		if (val <= MAX_PRICE) {
			coins.push_back(val);
			coin_count.insert({ val, 0 });
		}
		else {
			break;
		}
		k++;
	}

	sort(coins.begin(), coins.end());

	

	for(int i = 0; i < T; ++i) {
		unsigned long long price;
		cin >> price;
		
		for (auto const& x : coin_count) {
			coin_count[x.first] = 0;
		}

		unsigned long long count = 0;
		for (auto it = coins.rbegin(); it != coins.rend(); ++it) {
			ull val = *it;
			coin_count[val] += (price / val);
			price %= val;
			if (price == 0) { break; }
		}
		

		for (int i = 0; i < coins.size(); ++i) {
			if (i % 3 == 2) {
				ull v1 = coins[i - 2];
				ull v2 = coins[i - 1];
				ull v3 = coins[i];

				if (coin_count[v1] >= 5 && coin_count[v3] >= 1) {
					coin_count[v1] -= 5;
					coin_count[v3] -= 1;
					coin_count[v2] += 3;
				}
			}
		}

		ull sum = 0;
		for (auto it = coin_count.begin(); it != coin_count.end(); ++it) {
			sum += (*it).second;
		}

		cout << sum << endl;
	}
	
}
