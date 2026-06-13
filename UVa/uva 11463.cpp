// By xiplus
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int sol() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n, vector<int>(n, 1e9));
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}
	int s, t;
	for (int i = 0; i < m; i++) {
		cin >> s >> t;
		dp[s][t] = dp[t][s] = 1;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}
	cin >> s >> t;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[s][i] + dp[i][t]);
	}
	return ans;
}
signed main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": " << sol() << endl;
		;
	}
}
