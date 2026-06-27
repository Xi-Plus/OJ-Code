// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> dp;
string s;
const int MAX = 1e9;
int new_target, temp;
int k;
int dfs(int target, int len) {
	if (target <= 0) {
		return 0;
	}
	if (len < 0) {
		return MAX;
	}
	if (target > k) {
		return MAX;
	}
	if (dp[target][len] != -1) {
		return dp[target][len];
	}
	dp[target][len] = MAX;
	new_target = target;
	if (len >= 2 && (s[len - 2] == 'A') && (s[len - 1] == 'B') && (s[len] == 'C')) {
		new_target += 1;
	}
	temp = dfs(new_target, len - 1);
	if (temp < dp[target][len]) {
		dp[target][len] = temp;
	}

	if (len >= 2) {
		new_target = target - 1;
		if (len >= 2 && (s[len - 2] == 'A') && (s[len - 1] == 'B') && (s[len] == 'C')) {
			new_target = target;
		} else if (len >= 3 && (s[len - 3] == 'A') && (s[len - 2] == 'B') && (s[len - 1] == 'C')) {
			new_target = target;
		} else if (len >= 4 && (s[len - 4] == 'A') && (s[len - 3] == 'B') && (s[len - 2] == 'C')) {
			new_target = target;
		}
		temp = dfs(new_target, len - 3) + 3 - (s[len - 2] == 'A') - (s[len - 1] == 'B') - (s[len] == 'C');
		if (temp < dp[target][len]) {
			dp[target][len] = temp;
		}
	}
	return dp[target][len];
}
void sol() {
	cin >> s >> k;
	dp.assign(k + 1, vector<int>(s.size(), -1));
	int ans = dfs(k, s.size() - 1);
	if (ans == MAX) {
		ans = -1;
	}
	cout << ans << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
