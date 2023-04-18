/*
https://softeer.ai/practice/info.do?idx=1&eid=1526
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<string> DNAs;
int answer;

void DFS(int curIdx, vector<string>& supers);

void Solve() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		string temp;
		cin >> temp;
		DNAs.push_back(temp);
	}

	answer = N;
	vector<string> d;
	d.push_back(DNAs[0]);
	DFS(1, d);

	cout << answer << endl;
}

inline string merge(const string& super, const string& dna) {
	string ret = super;
	for (int i = 0; i < M; ++i) {
		if (ret[i] != '.') { continue; }
		ret[i] = dna[i];
	}
	return ret;
}

void DFS(int curIdx, vector<string>& supers) {
	
	if (curIdx == N) {
		int size = supers.size();
		answer = min(answer, size);
		return;
	}

	vector<string> supersCpy = supers;
	vector<int> mergableIdxs;

	for (int i = 0; i < supersCpy.size(); ++i) {
		string temp = supersCpy[i];

		bool isMergable = true;
		for (int j = 0; j < M; ++j) {
			if (supersCpy[i][j] != '.' && DNAs[curIdx][j] != '.' && supersCpy[i][j] != DNAs[curIdx][j]) {
				isMergable = false;
				break;
			}
		}

		if (isMergable) {
			supersCpy[i] = merge(supersCpy[i], DNAs[curIdx]);
			if (supersCpy.size() <= answer) {
				DFS(curIdx + 1, supersCpy);
			}
			supersCpy[i] = temp;
		}
	}

	supersCpy.push_back(DNAs[curIdx]);
	DFS(curIdx + 1, supersCpy);
	supersCpy.pop_back();

}

int main() {
	Solve();
	return 0;
}