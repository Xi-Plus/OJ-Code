// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long MAXV = 1e18;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<long long>> dp(n + 5, vector<long long>(n + 5, MAXV));
	dp[0][1] = 0;
	int l, p;
	for (int i = 1; i <= n - 1; i++) {
		cin >> l >> p;
		for (int j = 1; j <= i + 1; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= l + 1) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + p);
			}
		}
	}
	cin >> l >> p;
	if (l > n + 1 || dp[n - 1][l] == MAXV) {
		cout << -1 << endl;
	} else {
		cout << dp[n - 1][l] + p << endl;
	}
}
