// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<long long> a(n + 1), b(n + 1), t(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		t[i] = min(a[i], b[i]);
		ans += t[i];
	}
	char c;
	int x, v;
	while (q--) {
		cin >> c >> x >> v;
		if (c == 'A') {
			ans -= t[x];
			a[x] = v;
			t[x] = min(a[x], b[x]);
			ans += t[x];
			cout << ans << endl;
		} else {
			ans -= t[x];
			b[x] = v;
			t[x] = min(a[x], b[x]);
			ans += t[x];
			cout << ans << endl;
		}
	}
}
