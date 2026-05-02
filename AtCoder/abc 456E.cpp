// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool found;
vector<vector<int>> g;
vector<int> vis;
void dfs(int cur) {
	if (vis[cur] == 1) {
		found = true;
		return;
	}
	if (vis[cur] == 2) {
		return;
	}
	vis[cur] = 1;
	for (int nxt : g[cur]) {
		dfs(nxt);
	}
	vis[cur] = 2;
}
void sol() {
	int n, m;
	cin >> n >> m;
	vector<int> u(m), v(m);
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i];
	}
	int w;
	cin >> w;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	g.clear();
	g.resize((n + 1) * w + 5);
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < m; j++) {
			if (s[u[j] - 1][i] == 'o' && s[v[j] - 1][(i + 1) % w] == 'o') {
				g[u[j] * w + i].push_back(v[j] * w + (i + 1) % w);
			}
			if (s[v[j] - 1][i] == 'o' && s[u[j] - 1][(i + 1) % w] == 'o') {
				g[v[j] * w + i].push_back(u[j] * w + (i + 1) % w);
			}
		}
		for (int j = 1; j <= n; j++) {
			if (s[j - 1][i] == 'o' && s[j - 1][(i + 1) % w] == 'o') {
				g[j * w + i].push_back(j * w + (i + 1) % w);
			}
		}
	}
	vis.clear();
	vis.resize((n + 1) * w + 5, 0);
	found = false;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1][0] == 'o') {
			if (!vis[i * w]) {
				dfs(i * w);
			}
			if (found) {
				break;
			}
		}
	}
	if (found) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
