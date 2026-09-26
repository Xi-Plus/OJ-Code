// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, d;
	cin >> n >> d;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	vector<int> ans;
	if (v[1].first - v[0].first >= d) {
		ans.push_back(v[0].second);
	}
	for (int i = 1; i < n - 1; i++) {
		if (v[i].first - v[i - 1].first >= d && v[i + 1].first - v[i].first >= d) {
			ans.push_back(v[i].second);
		}
	}
	if (v[n - 1].first - v[n - 2].first >= d) {
		ans.push_back(v[n - 1].second);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	if (ans.size()) {
		for (auto& a : ans) {
			cout << a << " ";
		}
		cout << endl;
	}
}
