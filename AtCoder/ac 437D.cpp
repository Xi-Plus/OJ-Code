// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MOD = 998244353;

int bit[600005];
int lowbit(int x) {
	return x & -x;
}
int query(int x) {
	int res = 0;
	while (x > 0) {
		res += bit[x];
		x -= lowbit(x);
	}
	return res;
}
void update(int x) {
	while (x <= 600005) {
		bit[x] += 1;
		x += lowbit(x);
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<long long> a(n), b(m), c(n + m), fa(n);
	vector<long long> sa(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[i] = a[i];
	}
	sort(a.begin(), a.end());
	sa[0] = 0;
	for (int i = 1; i <= n; i++) {
		sa[i] = sa[i - 1] + a[i - 1];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		c[i + n] = b[i];
	}
	sort(c.begin(), c.end());
	for (int i = 0; i < n; i++) {
		update(lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1);
	}
	cout << endl;
	int fb, idx;
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		fb = lower_bound(c.begin(), c.end(), b[i]) - c.begin() + 1;
		idx = query(fb - 1);
		ans += (b[i] * idx - sa[idx]) % MOD;
		ans += (sa[n] - sa[idx] - b[i] * (n - idx)) % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
}
