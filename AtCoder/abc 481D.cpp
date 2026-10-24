// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> G[200005];
int small[200005];
bool vis[200005];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
signed main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		if (small[a] == 0) {
			small[a] = b;
		} else {
			small[a] = min(small[a], b);
		}
	}
	pq.push({0, s});
	while (!pq.empty()) {
		auto [dis, cur] = pq.top();
		pq.pop();
		if (vis[cur]) {
			continue;
		}
		vis[cur] = true;
		if (cur == t) {
			cout << dis << endl;
			return 0;
		}
		for (auto next : G[cur]) {
			if (!vis[next]) {
				if (small[cur] == next) {
					pq.push({dis, next});
				} else {
					pq.push({dis + 1, next});
				}
			}
		}
	}
	cout << -1 << endl;
}
