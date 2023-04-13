/*
https://www.acmicpc.net/problem/10815
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; //보유 카드 수
vector<int> cards; //카드 번호들
int M; //문제 수 : input 값에 해당하는 카드 번호가 있는지 판단 : 있으면 1 아니면 0


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cards.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());

	cin >> M;
	for (int m = 0; m < M; ++m) {
		int num;
		cin >> num;
		int answer = 0;

		int left = 0;
		int right = N - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (cards[mid] == num) {
				answer = 1;
				break;
			}

			if (cards[mid] > num) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		cout << answer << ' ';
	}
	cout << '\n';

	return 0;
}