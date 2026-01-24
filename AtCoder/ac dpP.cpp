// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> G;
long long dp[100005][2] = {};
const long long MOD = 1000000007;

void dfs(int cur, int from) {
	dp[cur][0] = 1;
	dp[cur][1] = 1;
	for (int next : G[cur]) {
		if (next == from) {
			continue;
		}
		dfs(next, cur);
		dp[cur][0] = dp[cur][0] * (dp[next][0] + dp[next][1]) % MOD;
		dp[cur][1] = dp[cur][1] * dp[next][0] % MOD;
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	G.resize(n + 1);
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, -1);
	cout << (dp[1][0] + dp[1][1]) % MOD << endl;
}
