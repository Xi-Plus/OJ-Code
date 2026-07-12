// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	long long ab[n + 1][2];
	for (int i = 1; i <= n; i++) {
		cin >> ab[i][0] >> ab[i][1];
	}
	long long dp[n + 1][k * 2 + 1] = {};
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + ab[i][0];
		// cerr << dp[i][0] << " ";
		for (int j = 1; j <= k * 2; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + ab[i][j & 1];
			// cerr << dp[i][j] << " ";
		}
		// cerr << endl;
	}
	long long ans = 0;
	for (int i = 0; i <= k * 2; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl;
}
