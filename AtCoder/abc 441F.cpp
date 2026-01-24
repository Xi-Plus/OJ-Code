// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1000, W = 50000;
int value[N + 1], price[N + 1];
long long dp1[N + 1][W + 1];
long long dp2[N + 1][W + 1];
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> price[i] >> value[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < price[i]; j++) {
			dp1[i + 1][j] = dp1[i][j];
		}
		for (int j = price[i]; j <= m; j++) {
			dp1[i + 1][j] = max(dp1[i][j], dp1[i][j - price[i]] + value[i]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < price[i]; j++) {
			dp2[i][j] = dp2[i + 1][j];
		}
		for (int j = price[i]; j <= m; j++) {
			dp2[i][j] = max(dp2[i + 1][j], dp2[i + 1][j - price[i]] + value[i]);
		}
	}
	long long target = dp1[n][m];
	for (int i = 0; i < n; i++) {
		long long without = 0;
		for (int j = 0; j <= m; j++) {
			without = max(without, dp1[i][j] + dp2[i + 1][m - j]);
		}
		long long with = 0;
		for (int j = 0; j <= m - price[i]; j++) {
			with = max(with, dp1[i][j] + dp2[i + 1][m - j - price[i]]);
		}
		with += value[i];
		if (without < target) {
			cout << "A";
		} else if (with < target) {
			cout << "C";
		} else {
			cout << "B";
		}
	}
	cout << endl;
}
