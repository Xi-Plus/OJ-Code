// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> G;
vector<int> color;
long long dp[100005][2] = {};
const long long MOD = 1000000007;

void dfs(int cur) {
	if (color[cur] == 1) {
		dp[cur][0] = 0;
		dp[cur][1] = 1;
	} else {
		dp[cur][0] = 1;
		dp[cur][1] = 0;
	}
	for (int next : G[cur]) {
		dfs(next);
		long long new1 = (dp[cur][1] * dp[next][1] + dp[cur][1] * dp[next][0] + dp[cur][0] * dp[next][1]) % MOD;
		long long new0 = (dp[cur][0] * dp[next][0] + dp[cur][0] * dp[next][1]) % MOD;
		dp[cur][0] = new0;
		dp[cur][1] = new1;
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	G.resize(n);
	color.resize(n);
	int a;
	for (int i = 1; i <= n - 1; i++) {
		cin >> a;
		G[a].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		cin >> color[i];
	}
	dfs(0);
	cout << dp[0][1] << endl;
}
