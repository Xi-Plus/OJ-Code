// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

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
	priority_queue<tuple<long long, long long, int>, vector<tuple<long long, long long, int>>, greater<tuple<long long, long long, int>>> q;
	bool visited[n + 1];
	fill_n(visited, n + 1, false);
	q.push({0, 0, 1});
	while (!q.empty()) {
		auto [dis, weight, cur] = q.top();
		q.pop();
		if (dis > ans[cur]) {
			continue;
		}
		ans[cur] = min(ans[cur], dis);
		weight += w[cur];
		for (int next : edges[cur]) {
			q.push({ans[cur] + weight, weight, next});
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
}
