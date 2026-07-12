// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<long long> a, b;
int n;
long long x;
long long remain;
struct MyHash {
	size_t operator()(const pair<long long, int>& p) const {
		return hash<long long>{}(p.first) ^ hash<int>{}(p.second);
	}
};
unordered_map<pair<long long, int>, long long, MyHash> cache;
long long calc(long long upper, int idx) {
	if (idx == n) {
		return 0;
	}
	if (upper <= 0) {
		return 0;
	}
	if (cache.count({upper, idx})) {
		return cache[{upper, idx}];
	}
	// cerr << "upper " << upper << " idx " << idx << endl;
	// cerr << "Add " << upper / a[idx] << endl;
	if (upper < a[idx]) {
		return cache[{upper, idx}] = calc(upper, idx + 1);
	}
	long long times = upper / a[idx];
	long long ans = times;
	remain = upper % a[idx];
	if (remain) {
		ans += calc(remain, idx + 1);
	}
	ans += times * calc(a[idx] - 1, idx + 1);
	return cache[{upper, idx}] = ans;
}
long long force() {
	long long ans = 0;
	for (long long i = 1; i <= x; i++) {
		long long temp = i;
		for (int j = 0; j < n; j++) {
			temp %= a[j];
		}
		ans += (temp == 0);
	}
	return ans;
}
void sol() {
	cin >> n >> x;
	b.resize(n);
	for (auto& v : b) {
		cin >> v;
	}
	cache.clear();
	a.clear();
	long long prev = 9e18;
	for (auto& v : b) {
		if (v < prev) {
			a.push_back(v);
			prev = v;
		}
	}
	n = a.size();
	// cerr << "clear to " << n << endl;
	// force();
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
