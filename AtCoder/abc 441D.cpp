// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, l;
	long long s, t;
	cin >> n >> m >> l >> s >> t;
	vector<pair<int, long long>> G[n + 1];
	int u, v, c;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		G[u].push_back({v, c});
	}
	vector<pair<int, long long>> va, vb;
	va.push_back({1, 0});
	while (l--) {
		for (auto& cur : va) {
			for (auto& nei : G[cur.first]) {
				vb.push_back({nei.first, cur.second + nei.second});
			}
		}
		va.clear();
		swap(va, vb);
	}
	set<int> ans;
	for (auto& cur : va) {
		if (s <= cur.second && cur.second <= t) {
			ans.insert(cur.first);
		}
	}
	for (auto& cur : ans) {
		cout << cur << " ";
	}
	cout << endl;
}
