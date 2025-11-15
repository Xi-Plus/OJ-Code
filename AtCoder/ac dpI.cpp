// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	double p;
	double dp[n + 1][n + 1] = {};
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> p;
		for (int j = 0; j <= i; j++) {
			dp[i + 1][j] += dp[i][j] * (1 - p);
			dp[i + 1][j + 1] += dp[i][j] * p;
		}
	}
	double ans = 0;
	for (int i = n / 2 + 1; i <= n; i++) {
		ans += dp[n][i];
	}
	cout << fixed << setprecision(20) << ans << endl;
}
