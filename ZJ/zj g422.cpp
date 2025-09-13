// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int idx, dis;
	bool operator<(const Node& rhs) const {
		return dis > rhs.dis;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, dst;
	cin >> n >> m >> dst;
	vector<pair<int, int>> edges[n];
	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		edges[a].push_back({b, w});
		edges[b].push_back({a, w});
	}
	int ans[n];
	fill_n(ans, n, 1e9);
	ans[0] = 0;
	priority_queue<Node> q;
	q.push({0, 0});
	bool visited[n] = {};
	while (!q.empty()) {
		auto [cur, dis] = q.top();
		q.pop();
		if (visited[cur]) {
			continue;
		}
		visited[cur] = true;
		for (auto& [next, weight] : edges[cur]) {
			if (dis + weight < ans[next]) {
				ans[next] = dis + weight;
				q.push({next, dis + weight});
			}
		}
	}
	cout << ans[dst] << endl;
}
