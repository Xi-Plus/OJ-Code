// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long a, b, c, d, e, f, t;
	while (cin >> a >> b >> c >> d >> e >> f) {
		long long ans = 0;
		t = min(a, f);
		ans += t;
		a -= t;
		f -= t;
		t = min(b, d);
		ans += t;
		b -= t;
		d -= t;
		t = min(c, e);
		ans += t;
		c -= t;
		e -= t;
		t = min(a, d);
		a -= t;
		d -= t;
		t = min(b, e);
		b -= t;
		e -= t;
		t = min(c, f);
		c -= t;
		f -= t;
		ans -= min(a, e);
		ans -= min(b, f);
		ans -= min(c, d);
		cout << abs(ans) << endl;
	}
}
/*
3 2 1
1 2 3
*/
