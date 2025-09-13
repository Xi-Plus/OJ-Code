// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int idx;
	long long fuel, weight;
	bool operator<(const Node& rhs) const {
		if (weight != rhs.weight) {
			return weight > rhs.weight;
		}
		return fuel > rhs.fuel;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	long long w[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	vector<int> edges[n + 1];
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	long long ans[n + 1];
	fill_n(ans, n + 1, 1e18);
	ans[1] = 0;
	priority_queue<Node> q;
	q.push({1, 0, w[1]});
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		for (int next : edges[cur.idx]) {
			if (cur.fuel + cur.weight < ans[next]) {
				ans[next] = cur.fuel + cur.weight;
				q.push({next, ans[next], cur.weight + w[next]});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
}
