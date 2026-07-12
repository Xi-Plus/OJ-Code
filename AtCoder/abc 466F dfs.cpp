// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<long long> a, b;
int n;
long long x;
vector<long long> dp;
long long calc(long long upper, int idx) {
	if (idx == n) {
		return 0;
	}
	if (upper <= 0) {
		return 0;
	}
	if (upper < a[idx]) {
		auto it = lower_bound(a.begin() + idx, a.end(), upper, greater<long long>());
		if (it == a.end()) {
			return 0;
		}
		idx = it - a.begin();
	}
	long long times = upper / a[idx];
	long long ans = times;
	long long remain = upper % a[idx];
	if (remain) {
		ans += calc(remain, idx + 1);
	}
	if (dp[idx] == -1) {
		dp[idx] = calc(a[idx] - 1, idx + 1);
	}
	ans += times * dp[idx];
	return ans;
}
void sol() {
	cin >> n >> x;
	b.resize(n);
	for (auto& v : b) {
		cin >> v;
	}
	a.clear();
	long long prev = 9e18;
	for (auto& v : b) {
		if (v < prev) {
			a.push_back(v);
			prev = v;
		}
	}
	n = a.size();
	dp.assign(n, -1);
	cout << calc(x, 0) << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
