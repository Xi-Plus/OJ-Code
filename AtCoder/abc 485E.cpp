// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int dis, color, idx;
	bool operator<(const Node& other) const {
		return dis > other.dis;
	}
};
vector<pair<int, int>> G[200005];
int vis[200005];
set<pair<int, int>> used;
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		G[a].push_back({b, c});
	}
	priority_queue<Node, vector<Node>> pq;
	pq.push({0, -1, 1});
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (cur.idx == n) {
			cout << cur.dis << "\n";
			return 0;
		}
		if (vis[cur.idx] >= 2) {
			continue;
		}
		if (used.count({cur.idx, cur.color})) {
			continue;
		}
		used.insert({cur.idx, cur.color});
		vis[cur.idx]++;
		for (auto& next : G[cur.idx]) {
			if (next.second == cur.color) {
				continue;
			}
			pq.push({cur.dis + 1, next.second, next.first});
		}
	}
	cout << "-1\n";
}
