// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int a[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	a[n] = 2e9 + 5;
	int x, y;
	while (q--) {
		cin >> x >> y;
		int idx = lower_bound(a, a + n, x) - a;
		int l = idx, r = n;
		while (l <= r) {
			int m = (l + r) / 2;
			// cout << "check " << m << " " << a[m] - x - (m - idx + 1) << endl;
			if (a[m] - x - (m - idx + 1) < y - 1) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		// cout << idx << " " << l << " " << r << endl;
		int ans = x + y + (l - idx) - 1;
		// if (ans == a[l]) {
		// 	ans++;
		// }
		cout << ans << endl;
	}
}
