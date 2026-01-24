// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
vector<vector<int>> G;
vector<long long> sz;
long long ans = 0;

void dfs(int cur, int from) {
	sz[cur] = 1;
	for (int next : G[cur]) {
		if (next == from) {
			continue;
		}
		dfs(next, cur);
		sz[cur] += sz[next];
		ans += sz[next] * (n - sz[next]);
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	G.resize(n + 1);
	sz.resize(n + 1);
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, -1);
	cout << ans << endl;
}
