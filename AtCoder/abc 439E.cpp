// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [](auto& l, auto& r) {
		if (l.first != r.first) {
			return l.first < r.first;
		}
		return l.second > r.second;
	});
	vector<int> dp;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(dp.begin(), dp.end(), v[i].second) - dp.begin();
		if (idx == dp.size()) {
			dp.push_back(v[i].second);
		} else {
			dp[idx] = v[i].second;
		}
	}
	cout << dp.size() << endl;
}
