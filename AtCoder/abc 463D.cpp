// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, k;
vector<pair<int, int>> v;

bool check(int gap) {
	int pos = -1, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second >= pos) {
			cnt++;
			if (cnt == k) {
				return true;
			}
			pos = v[i].first + gap;
		}
	}
	return false;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	int l = 1, r = 1e9, m;
	while (l <= r) {
		m = (l + r) / 2;
		if (check(m)) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	if (r == 0) {
		cout << -1 << endl;
	} else if (check(r)) {
		cout << r << endl;
	} else {
		cout << r - 1 << endl;
	}
}
