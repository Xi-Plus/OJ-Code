#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dp[1000005];

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	string outputs[] = {"", "Stan wins", "Ollie wins"};
	int n, m, s, t;
	int choices[15];
	while (cin >> n >> m) {
		memset(dp, 0, sizeof(int) * (n + 5));
		for (int i = 0; i < m; i++) {
			cin >> choices[i];
			dp[choices[i]] = 1;
		}
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			if (dp[i] == 0) {
				dp[i] = 2;
				for (int j = m - 1; j >= 0; j--) {
					s = i - choices[j];
					if (s > 0 && dp[s] == 2) {
						dp[i] = 1;
					}
				}
			}
		}
		cout << outputs[dp[n]] << endl;
	}
}
