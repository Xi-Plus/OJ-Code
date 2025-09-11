// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long m1(long long a, long long b, long long c) {
	long long ans = 0, cnt;
	cnt = min(a, min(b, c));
	ans += cnt;
	a -= cnt;
	b -= cnt;
	c -= cnt;

	cnt = min(a / 3, c / 3);
	ans += cnt * 2;
	a -= cnt * 3;
	c -= cnt * 3;

	cnt = min(a / 2, c);
	ans += cnt;
	a -= cnt * 2;
	c -= cnt;

	cnt = min(a, c / 2);
	ans += cnt;
	a -= cnt;
	c -= cnt * 2;

	return ans;
}
long long m2(long long a, long long b, long long c) {
	long long ans = 0, cnt;
	cnt = min(a, min(b, c));
	ans += cnt;
	a -= cnt;
	b -= cnt;
	c -= cnt;

	cnt = min(a / 2, c);
	ans += cnt;
	a -= cnt * 2;
	c -= cnt;

	cnt = min(a, c / 2);
	ans += cnt;
	a -= cnt;
	c -= cnt * 2;

	return ans;
}
long long m3(long long a, long long b, long long c) {
	long long ans = 0, cnt;
	cnt = min(a, min(b, c));
	ans += cnt;
	a -= cnt;
	b -= cnt;
	c -= cnt;

	cnt = min(a, c / 2);
	ans += cnt;
	a -= cnt;
	c -= cnt * 2;

	cnt = min(a / 2, c);
	ans += cnt;
	a -= cnt * 2;
	c -= cnt;

	return ans;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		long long ans = 0, cnt;
		cnt = min(a, min(b, c));
		ans += cnt;
		a -= cnt;
		b -= cnt;
		c -= cnt;
		int aused, cused;

		cnt = min(a / 3, c / 3);
		ans += cnt * 2;
		a -= cnt * 3;
		c -= cnt * 3;
		aused += cnt * 2;
		cused += cnt * 2;

		cnt = min(a, c / 2);
		ans += cnt;
		a -= cnt;
		c -= cnt * 2;

		cnt = min(a / 2, c);
		ans += cnt;
		a -= cnt * 2;
		c -= cnt;

		if (a > c) {
			ans += a / 3;
		} else {
			ans += c / 3;
		}
		cout << ans << endl;
	}
}
