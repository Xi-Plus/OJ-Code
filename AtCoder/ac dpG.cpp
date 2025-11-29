// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> G[100005];
int dp[100005];

int dfs(int cur) {
	if (dp[cur] != -1) {
		return dp[cur];
	}
	int res = 0;
	for (auto& from : G[cur]) {
		res = max(res, dfs(from) + 1);
	}
	return dp[cur] = res;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int x, y;
	while (m--) {
		cin >> x >> y;
		G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = -1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dfs(i));
	}
	cout << ans << endl;
}
