// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int dp[n][2] = {};
	dp[0][s[0] == '1'] = 1;
	long long ans = dp[0][1];
	for (int i = 1; i < n; i++) {
		if (s[i] == '0') {
			dp[i][0] = dp[i - 1][1] + 1;
			dp[i][1] = dp[i - 1][0];
		} else {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1] + 1;
		}
		ans += dp[i][1];
	}
	cout << ans << endl;
}
