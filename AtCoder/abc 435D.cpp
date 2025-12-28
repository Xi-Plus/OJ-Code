// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> G[300005];
bool ans[300005];

void dfs(int v) {
	if (ans[v]) {
		return;
	}
	ans[v] = true;
	for (auto u : G[v]) {
		dfs(u);
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		G[y].push_back(x);
	}
	int q;
	cin >> q;
	int t, v;
	while (q--) {
		cin >> t >> v;
		if (t == 1) {
			dfs(v);
		} else {
			if (ans[v]) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
}
