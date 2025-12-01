// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve() {
	int n, h;
	cin >> n >> h;
	int curU = h, curL = h, now = 0;
	int t, l, u;
	bool ans = true;
	while (n--) {
		cin >> t >> l >> u;
		curU += t - now;
		curL -= t - now;
		if (curU < l || curL > u) {
			ans = false;
		}
		curU = min(curU, u);
		curL = max(curL, l);
		now = t;
	}
	if (ans) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
