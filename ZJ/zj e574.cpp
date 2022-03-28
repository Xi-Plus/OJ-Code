#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/**
 * Ollie, if val < testcase
 * Stan, if val == testcase
 */
int dp[1000005];

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int testcase = 0, n, m, s;
	int choices[15];
	while (cin >> n >> m) {
		testcase++;
		for (int i = 0; i < m; i++) {
			cin >> choices[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				s = i - choices[j];
				if (s >= 0 && dp[s] < testcase) {
					dp[i] = testcase;
					break;
				}
			}
		}
		if (dp[n] == testcase) {
			cout << "Stan wins" << endl;
		} else {
			cout << "Ollie wins" << endl;
		}
	}
}
