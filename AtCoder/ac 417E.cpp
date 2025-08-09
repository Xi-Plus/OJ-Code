// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool visited[1001];
int n, m, x, y;
int path[1001];
int pathcnt;
vector<set<int>> nei;

bool dfs(int nth, int cur) {
	if (cur == y) {
		pathcnt = nth;
		return true;
	}
	for (auto &next : nei[cur]) {
		if (!visited[next]) {
			visited[next] = true;
			path[nth] = next;
			if (dfs(nth + 1, next)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	int u, v;
	while (t--) {
		cin >> n >> m >> x >> y;
		nei.clear();
		nei.resize(n + 1);
		fill_n(visited, n + 1, false);
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			nei[u].insert(v);
			nei[v].insert(u);
		}
		path[0] = x;
		visited[x] = true;
		dfs(1, x);
		for (int i = 0; i < pathcnt; i++) {
			cout << path[i] << ' ';
		}
		cout << endl;
	}
}
