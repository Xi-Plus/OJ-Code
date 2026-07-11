// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int x, y, l, r, a, b;
	cin >> x >> y >> l >> r >> a >> b;
	int ans = (b - a) * y;
	if (max(l, a) <= min(r, b)) {
		ans += (min(r, b) - max(l, a)) * (x - y);
	}
	cout << ans << endl;
}
