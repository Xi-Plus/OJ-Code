// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;
vector<pair<int, int>> E[1001];
unordered_set<int> allans[1001];
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		E[a].push_back(make_pair(b, w));
		if (a == 1) {
			allans[b].insert(w);
		}
	}
	int t;
	for (int i = 0; i < n * 2; i++) {
		bool updated = false;
		for (int j = 1; j <= n; j++) {
			for (auto &ans : allans[j]) {
				for (auto &edge : E[j]) {
					t = ans ^ edge.second;
					if (!allans[edge.first].contains(t)) {
						allans[edge.first].insert(t);
						updated = true;
					}
				}
			}
		}
		if (!updated) {
			break;
		}
	}
	if (allans[n].size() == 0) {
		cout << -1 << endl;
	} else {
		int ans = 1e9;
		for (auto &t : allans[n]) {
			ans = min(ans, t);
		}
		cout << ans << endl;
	}
}
