// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	string s, t;
	cin >> n >> k >> s;
	map<string, int> cnt;
	int maxcnt = 0;
	for (int i = 0; i < n - k + 1; i++) {
		t = s.substr(i, k);
		cnt[t]++;
		maxcnt = max(maxcnt, cnt[t]);
	}
	cout << maxcnt << endl;
	for (auto it : cnt) {
		if (it.second == maxcnt) {
			cout << it.first << " ";
		}
	}
	cout << endl;
}
