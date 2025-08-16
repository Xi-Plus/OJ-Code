// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Hash1 {
	size_t operator()(const pair<int, int>& p) const {
		return (size_t)p.first << 32 | p.second;
	}
};

struct Hash2 {
	size_t operator()(const tuple<int, int, long long>& p) const {
		return ((size_t)get<0>(p) << 32) ^ ((size_t)get<1>(p) << 16) ^ get<2>(p);
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int x[n], y[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	unordered_map<pair<int, int>, long long, Hash1> m1;
	unordered_map<tuple<int, int, int>, long long, Hash2> m2;
	int dx, dy, gcd;
	long long len;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dx = x[j] - x[i];
			dy = y[j] - y[i];
			len = (long long)dx * dx + (long long)dy * dy;
			gcd = __gcd(dx, dy);
			dx /= gcd;
			dy /= gcd;
			if (dx < 0) {
				dx = -dx;
				dy = -dy;
			}
			m1[{dx, dy}]++;
			m2[{dx, dy, len}]++;
		}
	}
	long long cnt1 = 0, cnt2 = 0;
	for (auto& it : m1) {
		cnt1 += it.second * (it.second - 1) / 2;
	}
	for (auto& it : m2) {
		cnt2 += it.second * (it.second - 1) / 2;
	}
	cout << cnt1 - cnt2 / 2 << endl;
}
