// By xiplus
// WA
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> G;
int deg[200005];
int visid = 0;
int rootUsed[200005];
int deepPoint = 0, deepLength = 0;
void dfs1(int cur, int from, int length) {
	// cout << "dfs1: " << cur << " " << from << " " << length << endl;
	if (length > deepLength) {
		deepLength = length;
		deepPoint = cur;
	}
	if (deg[cur] < 4) {
		return;
	}
	for (auto v : G[cur]) {
		if (v != from && deg[v] >= 3) {
			dfs1(v, cur, length + 1);
		}
	}
}
int ans = 0;
void dfs2(int cur, int from, int length) {
	// cout << "dfs2: " << cur << " " << from << " " << length << endl;
	ans = max(ans, length);
	if (deg[cur] >= 4) {
		rootUsed[cur] = visid;
	} else {
		return;
	}
	for (auto v : G[cur]) {
		if (v != from && deg[v] >= 3) {
			dfs2(v, cur, length + 1);
		}
	}
}
void sol() {
	visid++;
	// cout << "Q: " << visid << endl;
	int n;
	cin >> n;
	G.clear();
	G.resize(n + 1);
	memset(deg, 0, sizeof(int) * (n + 1));
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	// for (int i = 1; i <= n; i++) {
	// 	cout << "point: " << i << " " << deg[i] << endl;
	// }
	ans = 1;
	for (int i = 1; i <= n; i++) {
		if (deg[i] >= 3 && rootUsed[i] != visid) {
			deepLength = 0;
			deepPoint = i;
			for (auto v : G[i]) {
				if (deg[v] >= 3) {
					dfs1(v, i, 1);
				}
			}
			// cout << "root: " << deepPoint << " " << i << endl;
			for (auto v : G[deepPoint]) {
				if (deg[v] >= 3) {
					dfs2(v, deepPoint, 2);
				}
			}
			rootUsed[deepPoint] = visid;
		}
	}
	cout << ans << endl;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		sol();
	}
}
