// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	long long x, y;
	cin >> n >> x >> y;
	long long gcdxy = __gcd(x, y);
	long long gx = x / gcdxy, gy = y / gcdxy;
	long long dg = gy - gx;
	long long va[n];
	for (int i = 0; i < n; i++) {
		cin >> va[i];
	}
	sort(va, va + n);
	long long a = 0, b = va[0], ans = va[0], c;
	// cout << "a=" << a << ", b=" << b << endl;
	// cout << "gx=" << gx << ", gy=" << gy << ", dg=" << dg << endl;
	for (int i = 1; i < n; i++) {
		// cout << i << " " << va[i] << " " << va[i - 1] << endl;
		if ((va[i] - va[i - 1]) % dg != 0) {
			cout << -1 << endl;
			return 0;
		}
		c = (va[i] - va[i - 1]) / dg;
		b -= gx * c;
		a += gy * c;
		// cout << "a=" << a << ", b=" << b << endl;
		if (b < 0) {
			cout << -1 << endl;
			return 0;
		}
		ans += b;
	}
	cout << ans << endl;
}
