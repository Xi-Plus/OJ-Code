// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long

struct Node {
	int dis;
	int next;
	bool operator<(const Node rhs) const {
		return dis > rhs.dis;
	}
};
signed main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, y;
	cin >> n >> m >> y;
	vector<pair<int, int>> edges[n + 3];
	int u, v, t;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> t;
		edges[u].push_back({v, t});
		edges[v].push_back({u, t});
	}
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		edges[i].push_back({n + 1, x});
		edges[n + 2].push_back({i, x});
	}
	edges[n + 1].push_back({n + 2, y});
	priority_queue<Node> pq;
	pq.push({0, 1});
	bool vis[n + 3] = {};
	int ans[n + 3];
	int found = 0;
	while (pq.size()) {
		auto [dis, cur] = pq.top();
		pq.pop();
		if (vis[cur]) {
			continue;
		}
		vis[cur] = true;
		ans[cur] = dis;
		if (cur <= n) {
			found++;
		}
		if (found == n) {
			break;
		}
		for (auto& [next, d] : edges[cur]) {
			if (!vis[next]) {
				pq.push({dis + d, next});
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
