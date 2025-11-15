// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s, t;
	cin >> s >> t;
	int dp[s.size() + 1][t.size() + 1] = {};
	int src[s.size() + 1][t.size() + 1];
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 1; j <= t.size(); j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				src[i][j] = 1;
			} else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					src[i][j] = 2;
				} else {
					dp[i][j] = dp[i][j - 1];
					src[i][j] = 3;
				}
			}
		}
	}
	int r = s.size(), c = t.size();
	vector<char> ans;
	while (r > 0 && c > 0) {
		if (src[r][c] == 1) {
			ans.push_back(s[r - 1]);
			r--;
			c--;
		} else if (src[r][c] == 2) {
			r--;
		} else {
			c--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
	cout << endl;
}
