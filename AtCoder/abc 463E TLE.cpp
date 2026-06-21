// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long

struct Node {
	int dis;
	int next;
	bool used = false;
	bool operator<(const Node rhs) const {
		return dis > rhs.dis;
	}
};
signed main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, y;
	cin >> n >> m >> y;
	vector<pair<int, int>> edges[n + 1];
	int u, v, t;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> t;
		edges[u].push_back({v, t});
		edges[v].push_back({u, t});
	}
	vector<int> x(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	priority_queue<Node> pq;
	pq.push({0, 1, false});
	bool vis[n + 1] = {};
	int ans[n + 1];
	fill(ans, ans + n + 1, 1e18);
	int found = 0, temp;
	while (pq.size()) {
		auto [dis, cur, used] = pq.top();
		pq.pop();
		if (vis[cur]) {
			continue;
		}
		vis[cur] = true;
		ans[cur] = dis;
		found++;
		if (found == n) {
			break;
		}
		for (auto& [next, d] : edges[cur]) {
			if (!vis[next]) {
				temp = dis + d;
				if (temp < ans[next]) {
					ans[next] = temp;
					pq.push({temp, next, used});
				}
			}
		}
		if (!used) {
			for (int i = 1; i <= n; i++) {
				if (!vis[i]) {
					temp = dis + x[cur] + x[i] + y;
					if (temp < ans[i]) {
						ans[i] = temp;
						pq.push({temp, i, true});
					}
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
