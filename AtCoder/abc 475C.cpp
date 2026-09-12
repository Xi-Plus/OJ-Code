// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long

vector<int> v;
int n, s;
long long L;
int ans(int type) {
	vector<int> v2(v.begin(), v.end());
	if (type == 1) {
		for (int i = 1; i < s; i++) {
			v2[i] *= 2;
		}
	} else {
		for (int i = s; i < n; i++) {
			v2[i] *= 2;
		}
	}
	for (int i = 1; i < n; i++) {
		cerr << v2[i] << " ";
	}
	cerr << endl;
	int l = s;
	long long total = 0;
	while (l >= 2 && total + v2[l - 1] <= L) {
		total += v2[l - 1];
		l--;
	}
	int r = s;
	int ans = r - l;
	for (int i = l; i <= s; i++) {
		while (r < n && total + v2[r] <= L) {
			total += v2[r];
			r++;
		}
		cerr << "i=" << i << " r=" << r << " total=" << total << endl;
		ans = max(ans, r - i + 1);
		total -= v2[i];
	}
	return ans;
}
signed main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s >> L;
	assert(2 <= n && n <= 8000);
	assert(1 <= s && s <= n);
	assert(0 <= L && L <= 1000000000000000000LL);
	v.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		cin >> v[i];
		assert(1 <= v[i] && v[i] <= 1000000000);
	}
	cout << max(ans(1), ans(2)) << endl;
}
