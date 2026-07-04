// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int RAIN = 0, SUN = 1;
void sol() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> x(n);
	for (auto& v : x) {
		cin >> v;
	}
	vector<int> y(n - 1);
	for (auto& v : y) {
		cin >> v;
	}
	long long dp[n][2] = {};
	if (s[0] == 'S') {
		dp[0][RAIN] -= x[0];
	} else {
		dp[0][SUN] -= x[0];
	}
	for (int i = 1; i < n; i++) {
		if (s[i] == 'R') {
			dp[i][RAIN] = max(dp[i - 1][RAIN], dp[i - 1][SUN]);
			dp[i][SUN] = max(dp[i - 1][RAIN] + y[i - 1], dp[i - 1][SUN]) - x[i];
		} else {
			dp[i][RAIN] = max(dp[i - 1][RAIN], dp[i - 1][SUN]) - x[i];
			dp[i][SUN] = max(dp[i - 1][RAIN] + y[i - 1], dp[i - 1][SUN]);
		}
	}
	cout << max(dp[n - 1][RAIN], dp[n - 1][SUN]) << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
