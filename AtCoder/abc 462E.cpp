// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
	long long a, b, x, y;
	cin >> a >> b >> x >> y;
	x = abs(x);
	y = abs(y);
	long long ans = min(x, y) * min(a, b) * 2;
	long long diff = abs(x - y);
	if (x > y) {
		ans += (diff + 1) / 2 * min(a, b * 3) + diff / 2 * min(b, a * 3);
	} else {
		ans += (diff + 1) / 2 * min(b, a * 3) + diff / 2 * min(a, b * 3);
	}
	cout << ans << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
