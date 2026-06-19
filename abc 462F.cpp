// MLE
// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> dp;
string s;
const int MAX = 2e9;
int dfs(int target, int len) {
	if (target == 0) {
		return 0;
	}
	if (len < 0) {
		return MAX;
	}
	if (dp[target][len] != -1) {
		cerr << "find " << target << " " << len << " " << dp[target][len] << endl;
		return dp[target][len];
	}
	dp[target][len] = dfs(target, len - 1);
	if (len >= 2) {
		int new_target = target - 1;
		if ((s[len - 2] == 'A') && (s[len - 1] == 'B') && (s[len] == 'C')) {
			new_target = target;
		} else if (len - 3 > 0 && (s[len - 3] == 'A') && (s[len - 2] == 'B') && (s[len - 1] == 'C')) {
			new_target = target;
		} else if (len - 4 > 0 && (s[len - 4] == 'A') && (s[len - 3] == 'B') && (s[len - 2] == 'C')) {
			new_target = target;
		} else if ((s[len - 1] == 'A') && (s[len] == 'B') && (s[len + 1] == 'C')) {
			new_target = target;
		} else if ((s[len] == 'A') && (s[len + 1] == 'B') && (s[len + 2] == 'C')) {
			new_target = target;
		}
		if (new_target != target - 1) {
			cerr << "find " << target << " " << len << " new_target " << new_target << endl;
		}
		int temp = dfs(new_target, len - 3) + 3 - (s[len - 2] == 'A') - (s[len - 1] == 'B') - (s[len] == 'C');
		if (temp < dp[target][len]) {
			dp[target][len] = temp;
			cout << "update temp " << temp << endl;
		}
	}
	cerr << "find " << target << " " << len << " " << dp[target][len] << endl;
	return dp[target][len];
}
void sol() {
	int k;
	cin >> s >> k;
	int cnt = 0;
	for (int i = 0; i < s.size() - 2; i++) {
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
			cnt++;
			i += 2;
		}
	}
	int target = cnt + k;
	if (target > s.size() * 3) {
		cout << -1 << endl;
		return;
	}
	dp.clear();
	dp.resize(k + 1, std::vector<int>(s.size(), -1));
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
