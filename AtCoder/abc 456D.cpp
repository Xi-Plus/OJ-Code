// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long MOD = 998244353;
long long dp[3][300005];
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	dp[s[0] - 'a'][0] = 1;
	for (int i = 1; i < n; i++) {
		int c = s[i] - 'a';
		for (int j = 0; j < 3; j++) {
			if (j != c) {
				dp[j][i] = dp[j][i - 1];
			}
		}
		dp[c][i] += 1;
		for (int j = 0; j < 3; j++) {
			dp[c][i] += dp[j][i - 1];
			dp[c][i] %= MOD;
		}
	}
	cout << (dp[0][n - 1] + dp[1][n - 1] + dp[2][n - 1]) % MOD << endl;
}
