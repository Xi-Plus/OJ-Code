// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int h[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int dp[n];
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
		for (int j = 2; j <= k; j++) {
			if (i - j < 0) {
				break;
			}
			dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
		}
	}
	cout << dp[n - 1] << endl;
}
