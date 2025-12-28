// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long a[3][300005];
long long dp[3][300005] = {};
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[0][i] = dp[0][i - 1] + a[0][i];
	}
	for (int i = 2; i <= n; i++) {
		dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]) + a[1][i];
	}
	for (int i = 3; i <= n; i++) {
		dp[2][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[2][i];
	}
	cout << dp[2][n] << endl;
}
