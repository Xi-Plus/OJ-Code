// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol1() {
	int n, c;
	long long m;
	cin >> n >> m >> c;
	int cnt[m] = {};
	long long a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++;
	}
	long long ans = 0;
	for (long long i = 0; i < m; i++) {
		long long s = i;
		int sum = 0;
		while (sum < c) {
			s++;
			s %= m;
			sum += cnt[s];
		}
		ans += sum;
		cout << i << " " << sum << endl;
	}
	cout << ans << endl;
}

void sol2() {
	int n, c;
	long long m;
	cin >> n >> m >> c;
	map<long long, int> cnt;
	long long a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++;
	}
	vector<pair<long long, int>> cnt2;
	for (auto [k, v] : cnt) {
		cnt2.push_back({k, v});
	}
	int l = 0, r = 0, sum = 0;
	long long ans = 0;

	while (sum < c) {
		sum += cnt2[r].second;
		r++;
		if (r == cnt2.size()) {
			r = 0;
		}
	}
	ans += (m - cnt2[cnt2.size() - 1].first + cnt2[0].first) * sum;
	sum -= cnt2[0].second;
	l = 1;

	while (l < cnt2.size()) {
		while (sum < c) {
			sum += cnt2[r].second;
			r++;
			if (r == cnt2.size()) {
				r = 0;
			}
		}
		ans += (cnt2[l].first - cnt2[l - 1].first) * sum;
		sum -= cnt2[l].second;
		l++;
	}
	cout << ans << endl;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	// sol1();
	sol2();
}
