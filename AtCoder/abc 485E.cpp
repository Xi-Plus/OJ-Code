// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int dis, color, idx;
};
vector<pair<int, int>> G[200005];
int vis[200005];
int used[200005];
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		G[a].push_back({b, c});
	}
	queue<Node> que;
	que.push({0, -1, 1});
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		if (cur.idx == n) {
			cout << cur.dis << "\n";
			return 0;
		}
		if (vis[cur.idx] >= 2) {
			continue;
		}
		if (vis[cur.idx] == 1 && used[cur.idx] == cur.color) {
			continue;
		}
		if (vis[cur.idx] == 0) {
			used[cur.idx] = cur.color;
		}
		vis[cur.idx]++;
		for (auto& next : G[cur.idx]) {
			if (next.second == cur.color) {
				continue;
			}
			que.push({cur.dis + 1, next.second, next.first});
		}
	}
	cout << "-1\n";
}
