// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MOD = 1000000007;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w;
	cin >> h >> w;
	char a[h + 1][w + 1];
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> a[i][j];
		}
	}
	a[1][1] = '#';
	int dp[h + 1][w + 1] = {};
	dp[1][1] = 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (a[i][j] == '.') {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
			}
		}
	}
	cout << dp[h][w] << endl;
}
