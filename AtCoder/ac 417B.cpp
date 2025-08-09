// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<int, int> cnt;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt[x]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (cnt.find(x) != cnt.end() && cnt[x] > 0) {
			cnt[x]--;
		}
	}
	for (auto it : cnt) {
		for (int i = 0; i < it.second; i++) {
			cout << it.first << ' ';
		}
	}
	return 0;
}
