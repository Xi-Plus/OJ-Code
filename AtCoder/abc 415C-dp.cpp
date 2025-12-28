// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t, n, next;
	bool dp[1 << 18];
	string s;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s;
		fill_n(dp, 1 << n, false);
		dp[0] = true;
		int sz = (1 << n);
		for (int i = 0; i < sz; i++) {
			if (dp[i]) {
				for (int j = 0; j < n; j++) {
					next = (i | (1 << j));
					if (s[next - 1] == '0') {
						dp[next] = true;
					}
				}
			}
		}
		if (dp[sz - 1]) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
