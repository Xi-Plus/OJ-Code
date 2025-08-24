// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	vector<int> score(n);
	for (int i = 0; i < m; i++) {
		int cnt0 = 0;
		for (int j = 0; j < n; j++) {
			if (s[j][i] == '0') {
				cnt0++;
			}
		}
		if (cnt0 <= n / 2) {
			for (int j = 0; j < n; j++) {
				if (s[j][i] == '0') {
					score[j]++;
				}
			}
		} else {
			for (int j = 0; j < n; j++) {
				if (s[j][i] == '1') {
					score[j]++;
				}
			}
		}
	}
	int maxscore = 0;
	for (int i = 0; i < n; i++) {
		maxscore = max(maxscore, score[i]);
	}
	for (int i = 0; i < n; i++) {
		if (score[i] == maxscore) {
			cout << i + 1 << ' ';
		}
	}
	cout << endl;
}
