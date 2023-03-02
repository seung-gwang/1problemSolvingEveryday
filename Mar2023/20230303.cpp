/*
https://www.acmicpc.net/problem/17609
*/
#include <iostream>
#include <string>

using namespace std;

void sol();

int main() {
	sol();
}

int isPal(int front, int back, string& str, bool sub);

void sol() {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		string inputStr;
		cin >> inputStr;

		int front = 0;
		int back = inputStr.length() - 1;
		int answer = isPal(front, back, inputStr, false);

		cout << answer << '\n';
	}
}

int isPal(int front, int back, string& str, bool sub) {
	int s = front;
	int e = back;

	int ret = 0;

	while (s < e) {
		if (str[s] != str[e]) {
			if (sub) { //부분 문자열일 경우 회문이 아니면 그냥 false 리턴
				ret = 0;
				goto RET;
			}
			else {
				if ((isPal(s + 1, e, str, true) || isPal(s, e - 1, str, true))) {
					ret = 1;
				}
				else {
					ret = 2;
				}
				goto RET;
			}
		}
		s++; e--;
	}

	//부분 문자열인데 이곳에 도달함 -> 회문이라는 뜻
	if (sub && ret == 0) { ret = 1; };

RET:
	return ret;
}

